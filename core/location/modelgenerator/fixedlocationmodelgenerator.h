#pragma once
#include "core/core.h"
#include "core/location/modelgenerator/ilocationmodelgenerator.h"
#include "core/location/template/locationtemplate.h"
#include "core/location/model/iitemmodel.h"

namespace Location
{
namespace Generator
{

class FixedLocationModelGenerator : public ILocationModelGenerator
{
public:
	FixedLocationModelGenerator(const Template::LocationTemplate& tpl);

	std::auto_ptr<Model::ILocationModel> generate() const override;

private:
	Model::IItemPtr itemWithSlot(const Template::Item& tplItem, const Template::Slot& slot) const;
	QImage mainImage(const Template::Slot& slot) const;
	QImage searchPanelImage(const Template::Item& tplItem) const;

private:
	const Template::LocationTemplate m_template;
};

}
}