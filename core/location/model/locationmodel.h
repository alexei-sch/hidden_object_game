#pragma once
#include "location/model/ilocationmodel.h"
#include "location/model/itemsmodel.h"

namespace Location
{
namespace Model
{

class LocationModel : public ILocationModel
{
public:
	LocationModel(const Items& items);
	const Items& activeItems() const override;
	const Items& foundItems() const override;
	void guess(const Common::PointF& point) override;

private:
	int findItem(const Common::PointF& point) const;

private:
	Items m_activeItems;
	Items m_foundItems;
};

}
}