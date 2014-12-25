#include "itemfoundanimation.h"

namespace Gui
{

using namespace Location;
using namespace Location::Model;

static const int s_accel = 2;//per sec

ItemFoundAnimation::ItemFoundAnimation(IItemPtr item, const QRect& locationBound)
	: m_item(item)
	, m_startTime(QDateTime::currentDateTimeUtc().toMSecsSinceEpoch())
	, m_direction(item->position().x() > locationBound.width() / 2 ? 1 : -1)
	, m_locationBound(locationBound)
{
}

void ItemFoundAnimation::paint(QPainter& painter)
{
	painter.drawImage(currentX(), m_item->position().y(), m_item->image());
}

int ItemFoundAnimation::currentX() const
{
	const quint64 deltaT = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch() - m_startTime;
	return m_item->position().x() + m_direction * static_cast<int>((s_accel * deltaT * deltaT / 2 ) / 1000);
}

bool ItemFoundAnimation::finished() const 
{
	return !m_locationBound.intersects(currentBound());
}

QRect ItemFoundAnimation::currentBound() const
{
	return QRect(QPoint(currentX(), m_item->position().y()), m_item->image().size());
}
}