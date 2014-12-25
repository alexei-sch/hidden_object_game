#include "xmllocationloadertest.h"
#include "location/template/xmllocationtemplateloader.h"

namespace Tests
{
using namespace Common;
using namespace Location;
using namespace Location::Template;
using namespace Location::Template::Persistence;

void XmlLocationTemplateLoaderTest::init()
{
	XmlLocationTemplateLoader loader(1);
	m_template = loader.load();
}

void XmlLocationTemplateLoaderTest::intersections()
{
	QVERIFY(m_template->intersections.contains(Intersection(1, 231)));
	QVERIFY(m_template->intersections.contains(Intersection(303, 215)));
	QVERIFY(m_template->intersections.contains(Intersection(291, 203)));

	QVERIFY(!m_template->intersections.contains(Intersection(123, 456)));
}

void XmlLocationTemplateLoaderTest::itemsCount()
{
	QCOMPARE(m_template->items.count(), 27);
}

void XmlLocationTemplateLoaderTest::itemAddingAtlas()
{
	QCOMPARE(m_template->items.isAddingAtlas(), false);
}

void XmlLocationTemplateLoaderTest::itemProperties1()
{
	const Item& item = m_template->items.item(0);

	QCOMPARE(item.name, QString("xmlitem.tutorMagnifer"));
	QCOMPARE(item.clipName, QString("tutorMagnifer"));

	QCOMPARE(item.searchPanel, ImageRect(Point(50, 224), Size(49, 23)));
}

void XmlLocationTemplateLoaderTest::itemProperties2()
{
	const Item& item = m_template->items.item(m_template->items.count() - 1);

	QCOMPARE(item.name, QString("xmlitem.umbrella"));
	QCOMPARE(item.clipName, QString("umbrella"));

	QCOMPARE(item.searchPanel, ImageRect(Point(150, 34), Size(48, 9)));
}

void XmlLocationTemplateLoaderTest::itemSlotsCount()
{
	const Item& item = m_template->items.item(0);

	QCOMPARE(item.slots.count(), 5);
}

void XmlLocationTemplateLoaderTest::itemSlot1()
{
	const Slot& slot = m_template->items.item(0).slots[0];

	QCOMPARE(slot.addName, QString("_01"));
	QCOMPARE(slot.id, ID(271));
	QCOMPARE(slot.location, PointF(243.3, 585.3));
	QCOMPARE(slot.image, ImageRect(Point(219, 915), Size(78, 36)));

}

void XmlLocationTemplateLoaderTest::itemSlot2()
{
	const Slot& slot = m_template->items.item(0).slots[4];

	QCOMPARE(slot.addName, QString("_05"));
	QCOMPARE(slot.id, ID(275));
	QCOMPARE(slot.location, PointF(22.7, 484.4));
	QCOMPARE(slot.image, ImageRect(Point(219, 951), Size(78, 36)));

}

void XmlLocationTemplateLoaderTest::itemSlot3()
{
	const Slot& slot = m_template->items.item(m_template->items.count() - 1).slots[4];

	QCOMPARE(slot.addName, QString("_05"));
	QCOMPARE(slot.id, ID(265));
	QCOMPARE(slot.location, PointF(459.8, 215.8));
	QCOMPARE(slot.image, ImageRect(Point(436, 855), Size(64, 22)));

}
}