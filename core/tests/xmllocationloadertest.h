#pragma once
#include "location/template/locationtemplate.h"

namespace Tests
{

class XmlLocationTemplateLoaderTest : public QObject
{
	Q_OBJECT

public:
	Q_INVOKABLE XmlLocationTemplateLoaderTest() {};

private:
	Q_SLOT void init();
	Q_SLOT void intersections();
	Q_SLOT void itemsCount();
	Q_SLOT void itemAddingAtlas();
	Q_SLOT void itemProperties1();
	Q_SLOT void itemProperties2();
	Q_SLOT void itemSlotsCount();
	Q_SLOT void itemSlot1();
	Q_SLOT void itemSlot2();
	Q_SLOT void itemSlot3();

private:
	std::auto_ptr<Location::Template::LocationTemplate> m_template;
};

}