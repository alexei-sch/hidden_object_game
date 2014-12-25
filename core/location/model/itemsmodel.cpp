#include "location/model/itemsmodel.h"

namespace Location
{
namespace Model
{
using namespace std;
using namespace std::tr1;

void Items::add(IItemPtr item)
{
	m_items << shared_ptr<IItem>(item);
}

IItemPtr Items::take(int index)
{
	Q_ASSERT(index >= 0 && index < m_items.count());
	return m_items.takeAt(index);
}

const IItem& Items::item(int index) const
{
	Q_ASSERT(index >= 0 && index < m_items.count());

	return *m_items[index];
}

int Items::count() const
{
	return m_items.count();
}

}
}