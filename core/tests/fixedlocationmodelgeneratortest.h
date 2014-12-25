#pragma once
#include "location/model/ilocationmodel.h"

namespace Tests
{

class FixedLocationModelGeneratorTest : public QObject
{
	Q_OBJECT

public:
	Q_INVOKABLE FixedLocationModelGeneratorTest() {};

private:
	Q_SLOT void init();
	Q_SLOT void itemsCount();
	Q_SLOT void itemName1();
	Q_SLOT void itemName2();
	Q_SLOT void itemPosition1();
	Q_SLOT void itemPosition2();
	Q_SLOT void itemImage1();
	Q_SLOT void itemImage2();
	Q_SLOT void itemSearchPanelImage1();
	Q_SLOT void itemSearchPanelImage2();

private:
	std::auto_ptr<Location::Model::ILocationModel> m_model;
};

}