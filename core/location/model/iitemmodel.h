#pragma once
#include "core/common/point.h"
#include "core/common/id.h"

namespace Location
{
namespace Model
{

class IItem
{
public:
	virtual ~IItem() {};

	virtual const QString& name() const = 0;
	virtual const QString& clipName() const = 0;
	virtual const Common::ID& id() const = 0;
	virtual const Common::PointF& position() const = 0;
	virtual const QImage& image() const = 0;
	virtual const QImage& imageForSearchPanel() const = 0;

	virtual bool hitTest(const Common::PointF& point) const = 0;
};

typedef std::tr1::shared_ptr<IItem> IItemPtr;
}
}