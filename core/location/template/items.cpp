#include "items.h"

namespace Location
{
namespace Template
{

Items::Items(bool isAddingAtlas)
	: m_isAddingAtlas(isAddingAtlas)
{
}

void Items::add(const Item& item)
{
	m_items << item;
}

int Items::count() const
{
	return m_items.count();
}

const Item& Items::item(int index) const
{
	Q_ASSERT(index >= 0 && index < m_items.count());

	return m_items[index];
}

bool Items::isAddingAtlas() const
{
	return m_isAddingAtlas;
}
}
}