#pragma once
#include "core/common/id.h"
#include "core/common/point.h"
#include "core/common/imagerect.h"

namespace Location
{
namespace Template
{

struct Slot
{
	Slot(const QString& addName, const Common::ID& id, 
		 const Common::PointF& location, const Common::ImageRect& image);

	const QString addName;
	const Common::ID id;
	const Common::PointF location;
	const Common::ImageRect image;
};

}
}