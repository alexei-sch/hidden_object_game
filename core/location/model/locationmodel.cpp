#include "locationmodel.h"

namespace Location
{
namespace Model
{
using namespace std;

LocationModel::LocationModel(const Items& items)
	: m_activeItems(items)
{
	Q_ASSERT(m_activeItems.count() > 0);
}

const Items& LocationModel::activeItems() const 
{
	return m_activeItems;
}

const Items& LocationModel::foundItems() const 
{
	return m_foundItems;
}

void LocationModel::guess(const Common::PointF& point)
{
	const int itemIndex = findItem(point);

	if (itemIndex >= 0)
	{
		IItemPtr item = m_activeItems.take(itemIndex);
		m_foundItems.add(item);

		Q_EMIT itemFound(item);
	}
}

int LocationModel::findItem(const Common::PointF& point) const
{
	for (int i = 0; i < m_activeItems.count(); ++i)
	{
		if (m_activeItems.item(i).hitTest(point))
		{
			return i;
		}
	}
	//FIXMMMMMMMEEEEEEEEEEEE
	return -1;
}

}
}