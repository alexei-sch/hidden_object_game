#pragma once
#include "resources.h"

namespace Resources
{
class ILocationResourceProvider;

class RES_EXPORT ResourceProvider
{
public:
	static std::auto_ptr<ILocationResourceProvider> location(int locationId);
	static QImage mainscreenBack();
	static QImage closeButton();
};

}