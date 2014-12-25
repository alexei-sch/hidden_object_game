#pragma once
#include "core/location/modelgenerator/ilocationmodelgenerator.h"
#include "core/location/template/locationtemplate.h"
#include "core/location/model/iitemmodel.h"

namespace Location
{
namespace Generator
{

//TODO
class RandomLocationModelGenerator : public ILocationModelGenerator
{
public:
	RandomLocationModelGenerator(const Template::LocationTemplate& tpl);

	std::auto_ptr<Model::ILocationModel> generate() const override;
};

}
}