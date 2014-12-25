#pragma once
#include "core/common/imagerect.h"
#include "slots.h"

namespace Location
{
namespace Template
{

struct Item
{
public:
	Item(const QString& name, const QString& clipName, const Common::ImageRect& searchPanel, const Slots& slots);

	const QString name;
	const QString clipName;
	const Common::ImageRect searchPanel;
	const Slots slots;
};

}
}