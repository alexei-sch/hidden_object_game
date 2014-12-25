#include "location/modelgenerator/fixedlocationmodelgenerator.h"
#include "location/model/locationmodel.h"
#include "location/model/itemmodel.h"

namespace Location
{
namespace Generator
{
using namespace std;
using namespace Model;
using namespace Template;

FixedLocationModelGenerator::FixedLocationModelGenerator(const Template::LocationTemplate& tpl)
	: m_template(tpl)
{
}

auto_ptr<ILocationModel> FixedLocationModelGenerator::generate() const 
{
	Model::Items items;

	for (int i = 0; i < m_template.items.count(); ++i)
	{
		const Template::Item& tplItem = m_template.items.item(i);
		const Template::Slot& slot = tplItem.slots[0];

		items.add(itemWithSlot(tplItem, slot));
	}

	return auto_ptr<ILocationModel>(new LocationModel(items));
}

IItemPtr FixedLocationModelGenerator::itemWithSlot(const Template::Item& tplItem, const Template::Slot& slot) const
{
	const QString clipName = tplItem.clipName + slot.addName;
	const QImage image = mainImage(slot);
	const QImage spImage = searchPanelImage(tplItem);

	return IItemPtr(new Model::Item(tplItem.name, clipName, slot.id, slot.location, image, spImage));
}

QImage FixedLocationModelGenerator::mainImage(const Template::Slot& slot) const
{
	return m_template.mainImage.copy(slot.image);
}

QImage FixedLocationModelGenerator::searchPanelImage(const Template::Item& tplItem) const
{
	return m_template.searchPanelImage.copy(tplItem.searchPanel);
}
}
}