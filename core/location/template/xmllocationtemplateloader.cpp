#include "xmllocationtemplateloader.h"
#include "locationtemplate.h"
#include "common/converter.h"
#include "resources/resourceprovider.h"
#include "resources/ilocationresourceprovider.h"

namespace Location
{
namespace Template
{
namespace Persistence
{
using namespace std;
using namespace Common;
using namespace Resources;

static const char* tagRoom = "room";

static const char* tagItems = "items";
static const char* attrIsAddingAtlas = "isAddingAtlas";

static const char* tagItem = "item";
static const char* attrName = "name";
static const char* attrClipName = "clipName";
static const char* attrSAX = "s_a_x";
static const char* attrSAY = "s_a_y";
static const char* attrSAW = "s_a_w";
static const char* attrSAH = "s_a_h";

static const char* tagSlot = "slot";
static const char* attrAddName = "addName";
static const char* attrID = "id";
static const char* attrRX = "r_x";
static const char* attrRY = "r_y";
static const char* attrAX = "a_x";
static const char* attrAY = "a_y";
static const char* attrAW = "a_w";
static const char* attrAH = "a_h";

static const char* tagIntersections = "intersections";
static const char* tagIntersectionIds = "intersectionIds";

XmlLocationTemplateLoader::XmlLocationTemplateLoader(const LocationId& locationId)
	: m_locationId(locationId)
{
}

static QString attribute(const QDomNamedNodeMap& attrs, const QString& name)
{
	Q_ASSERT(attrs.contains(name));

	const QDomNode node = attrs.namedItem(name);

	Q_ASSERT(node.nodeType() == QDomNode::AttributeNode);
	const QDomAttr attr = node.toAttr();
	Q_ASSERT(attr.name() == name);

	return attr.value();
}

static int intAttribute(const QDomNamedNodeMap& attrs, const QString& name)
{
	const QString attr = attribute(attrs, name);
	return Converter::toInt(attr);
}

static double doubleAttribute(const QDomNamedNodeMap& attrs, const QString& name)
{
	const QString attr = attribute(attrs, name);
	return Converter::toDouble(attr);
}

static ImageRect loadImageInfo(const QDomNamedNodeMap& attrs,
							   const QString& xname, const QString& yname, 
							   const QString& wname, const QString& hname)
{
	return ImageRect(Point(intAttribute(attrs, xname), intAttribute(attrs, yname)), 
					 Size(intAttribute(attrs, wname), intAttribute(attrs, hname)));
}

static Slot loadSlot(const QDomNode& slotNode)
{
	Q_ASSERT(slotNode.nodeName() == tagSlot);

	const QDomNamedNodeMap attrs = slotNode.attributes();

	const QString addName = attribute(attrs, attrAddName);
	const ID id = intAttribute(attrs, attrID);
	const PointF location = PointF(doubleAttribute(attrs, attrRX), doubleAttribute(attrs, attrRY));
	const ImageRect image = loadImageInfo(attrs, attrAX, attrAY, attrAW, attrAH);

	return Slot(addName, id, location, image);
}

static Slots loadSlots(const QDomNode& itemNode)
{
	Q_ASSERT(itemNode.nodeName() == tagItem);

	Slots slots;
	const QDomNodeList childs = itemNode.childNodes();
	for(int i = 0; i < childs.count(); ++i)
	{
		slots << loadSlot(childs.item(i));
	}
	return slots;
}

static Item loadItem(const QDomNode& itemNode)
{
	Q_ASSERT(itemNode.nodeName() == tagItem);

	const QDomNamedNodeMap attrs = itemNode.attributes();
	
	const QString name = attribute(attrs, attrName);
	const QString clipName = attribute(attrs, attrClipName);
	const ImageRect imageInfo = loadImageInfo(attrs, attrSAX, attrSAY, attrSAW, attrSAH);

	return Item(name, clipName, imageInfo, loadSlots(itemNode));
}

static Items loadItems(const QDomNode& room)
{
	Q_ASSERT(room.nodeName() == tagRoom);

	const QDomNode itemsNode = room.firstChild();
	Q_ASSERT(itemsNode.nodeName() == tagItems);

	const int addingAtlas = intAttribute(itemsNode.attributes(), attrIsAddingAtlas);
	Items items(addingAtlas);
	const QDomNodeList nodeList = itemsNode.childNodes();
	for(int i = 0; i < nodeList.count(); ++i)
	{
		items.add(loadItem(nodeList.item(i)));
	}
	return items;
}

static Intersection loadIntersection(const QDomNode& intersectionNode)
{
	Q_ASSERT(intersectionNode.nodeName() == tagIntersectionIds);

	Q_ASSERT(intersectionNode.nodeType() == QDomNode::ElementNode);
	const QDomElement element = intersectionNode.toElement();
	const QStringList pair = element.text().split(',', QString::SkipEmptyParts);
	Q_ASSERT(pair.count() == 2);

	return Intersection(ID(Converter::toInt(pair[0])), ID(Converter::toInt(pair[1])));
}

static Intersections loadIntersections(const QDomNode& room)
{
	Q_ASSERT(room.nodeName() == tagRoom);

	const QDomNode intersectionsNode = room.lastChild();
	Q_ASSERT(intersectionsNode.nodeName() == tagIntersections);

	Intersections intersections;
	const QDomNodeList nodeList = intersectionsNode.childNodes();
	for(int i = 0; i < nodeList.count(); ++i)
	{
		intersections.add(loadIntersection(nodeList.item(i)));
	}
	return intersections;
}

auto_ptr<LocationTemplate> XmlLocationTemplateLoader::load()
{
	const auto_ptr<ILocationResourceProvider> resource = ResourceProvider::location(m_locationId);

	QDomDocument document;
	document.setContent(resource->descriptionXML());

	Q_ASSERT(document.childNodes().count() == 1);

	const QDomNode room = document.firstChild();
	Q_ASSERT(room.nodeName() == tagRoom);

	const Items items = loadItems(room);
	const Intersections intersections = loadIntersections(room);

	return auto_ptr<LocationTemplate>(new LocationTemplate(items, intersections, resource->mainImage(), resource->searchPanelImage()));
}

}
}
}