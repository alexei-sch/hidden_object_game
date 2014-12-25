#pragma once
#include "core/location/template/items.h"
#include "core/location/template/intersections.h"

namespace Location
{
namespace Template
{

struct LocationTemplate
{
public:
	LocationTemplate(const Items& items, const Intersections& intersections, 
					 const QImage& mainImage, const QImage& searchPanelImage);

	const Items items;
	const Intersections intersections;
	const QImage mainImage;
	const QImage searchPanelImage;
};

}
}