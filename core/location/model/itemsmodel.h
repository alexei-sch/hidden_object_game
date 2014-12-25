#pragma once
#include "core/core.h"
#include "core/location/model/iitemmodel.h"

namespace Location
{
namespace Model
{
class CORE_EXPORT Items
{
public:
	void add(IItemPtr item);
	IItemPtr take(int index);

	const IItem& item(int index) const;
	int count() const;

private:
	QList<IItemPtr> m_items;
};

}
}