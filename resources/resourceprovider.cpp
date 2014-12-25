#include "resourceprovider.h"
#include "locationresourceprovider.h"

namespace Resources
{

std::auto_ptr<ILocationResourceProvider> ResourceProvider::location(int locationId)
{
	return std::auto_ptr<ILocationResourceProvider>(new LocationResourceProvider(locationId));
}

static const char* s_backround = ":data/mainscreen/background.png";
static const char* s_closeButton = ":data/common/closebutton.png";

static QImage image(const QString& path)
{
	Q_ASSERT(!QImage(path).isNull());

	return QImage(path);
}

QImage ResourceProvider::mainscreenBack()
{
	return image(s_backround);
}

QImage ResourceProvider::closeButton()
{
	return image(s_closeButton);
}

}