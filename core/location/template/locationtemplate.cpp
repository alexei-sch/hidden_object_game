#include "locationtemplate.h"

namespace Location
{
namespace Template
{

LocationTemplate::LocationTemplate(const Items& items, const Intersections& intersections, 
								   const QImage& mainImage, const QImage& searchPanelImage)
	: items(items)
	, intersections(intersections)
	, mainImage(mainImage)
	, searchPanelImage(searchPanelImage)
{
	Q_ASSERT(!mainImage.isNull());
	Q_ASSERT(!searchPanelImage.isNull());
}

}
}