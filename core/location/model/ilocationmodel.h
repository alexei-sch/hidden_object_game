#pragma once
#include "core/common/point.h"
#include "core/location/model/iitemmodel.h"

namespace Location
{
namespace Model
{
class Items;

class ILocationModel : public QObject
{
	Q_OBJECT
public:
	virtual ~ILocationModel() {};

	virtual const Items& activeItems() const = 0;
	virtual const Items& foundItems() const = 0;
	virtual void guess(const Common::PointF& point) = 0;

	Q_SIGNAL void itemFound(IItemPtr item);
};

}
}