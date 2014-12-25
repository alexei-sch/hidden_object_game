#pragma once
#include "core/location/locationid.h"

namespace Location
{
namespace Template
{
struct LocationTemplate;

namespace Persistence
{

//! No complex error-handling logic here. Just asserts since xml load from resources
class XmlLocationTemplateLoader
{
public:
	XmlLocationTemplateLoader(const LocationId& locationId);

	std::auto_ptr<LocationTemplate> load();

private:
	const LocationId m_locationId;
};

}
}
}