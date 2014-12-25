#pragma once
#include "core/location/template/item.h"

namespace Location
{
namespace Template
{

class Items
{
public:
	Items(bool isAddingAtlas);

	void add(const Item& item);
	int count() const;
	const Item& item(int index) const;
	bool isAddingAtlas() const;

private:
	QList<Item> m_items;
	const bool m_isAddingAtlas;
};

}
}