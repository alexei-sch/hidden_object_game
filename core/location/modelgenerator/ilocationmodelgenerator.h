#pragma once

namespace Location
{

namespace Template
{
struct LocationTemplate;
}
namespace Model
{
class ILocationModel;
}

namespace Generator
{

class ILocationModelGenerator
{
public:
	virtual ~ILocationModelGenerator() {};

	virtual std::auto_ptr<Model::ILocationModel> generate() const = 0;
};

}
}