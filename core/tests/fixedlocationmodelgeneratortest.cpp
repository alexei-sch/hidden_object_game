#include "fixedlocationmodelgeneratortest.h"
#include "location/template/xmllocationtemplateloader.h"
#include "location/modelgenerator/fixedlocationmodelgenerator.h"
#include "location/template/locationtemplate.h"
#include "location/model/itemsmodel.h"

using namespace std;
using namespace Common;
using namespace Location;
using namespace Location::Model;
using namespace Location::Generator;
using namespace Location::Template;
using namespace Location::Template::Persistence;

namespace Tests
{

void FixedLocationModelGeneratorTest::init()
{
	XmlLocationTemplateLoader loader(2);
	const auto_ptr<LocationTemplate> tpl = loader.load();

	const FixedLocationModelGenerator gen(*tpl);
	m_model = gen.generate();
}

void FixedLocationModelGeneratorTest::itemsCount()
{
	const Model::Items& items = m_model->activeItems();
	QCOMPARE(items.count(), 23);
}

void FixedLocationModelGeneratorTest::itemName1()
{
	const Model::IItem& item = m_model->activeItems().item(0);
	
	QCOMPARE(item.name(), QString("xmlitem.alarmclock"));
	QCOMPARE(item.clipName(), QString("alarmclock_01"));
	QCOMPARE(item.id(), ID(1));
}

void FixedLocationModelGeneratorTest::itemName2()
{
	const Model::IItem& item = m_model->activeItems().item(22);

	QCOMPARE(item.name(), QString("xmlitem.ringbell"));
	QCOMPARE(item.clipName(), QString("bell_01"));
	QCOMPARE(item.id(), ID(241));
}

void FixedLocationModelGeneratorTest::itemPosition1()
{
	const Model::IItem& item = m_model->activeItems().item(0);

	QCOMPARE(item.position(), PointF(469.8, 432.7));
}

void FixedLocationModelGeneratorTest::itemPosition2()
{
	const Model::IItem& item = m_model->activeItems().item(22);

	QCOMPARE(item.position(), PointF(133.7, 521.6));
}

void FixedLocationModelGeneratorTest::itemImage1()
{
	const Model::IItem& item = m_model->activeItems().item(0);

	QCOMPARE(item.image().size(), QSize(39, 55));
}

void FixedLocationModelGeneratorTest::itemImage2()
{
	const Model::IItem& item = m_model->activeItems().item(22);

	QCOMPARE(item.image().size(), QSize(30, 69));
}

void FixedLocationModelGeneratorTest::itemSearchPanelImage1()
{
	const Model::IItem& item = m_model->activeItems().item(0);

	QCOMPARE(item.imageForSearchPanel().size(), QSize(35, 50));
}

void FixedLocationModelGeneratorTest::itemSearchPanelImage2()
{
	const Model::IItem& item = m_model->activeItems().item(22);

	QCOMPARE(item.imageForSearchPanel().size(), QSize(22, 50));
}

}