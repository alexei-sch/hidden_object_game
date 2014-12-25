#include "item.h"

namespace Location
{
namespace Template
{

Item::Item(const QString& name, const QString& clipName, const Common::ImageRect& searchPanel, const Slots& slots)
	: name(name)
	, clipName(clipName)
	, searchPanel(searchPanel)
	, slots(slots)
{
	Q_ASSERT(!name.isEmpty());
	Q_ASSERT(!clipName.isEmpty());
	Q_ASSERT(!slots.isEmpty());
}

}
}