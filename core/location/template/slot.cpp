#include "slot.h"

namespace Location
{
namespace Template
{

Slot::Slot(const QString& addName, const Common::ID& id, const Common::PointF& location, const Common::ImageRect& image) 
	: addName(addName)
	, id(id)
	, location(location)
	, image(image)
{
}

}
}