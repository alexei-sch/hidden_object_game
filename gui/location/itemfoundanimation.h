#pragma once
#include "core/location/model/iitemmodel.h"
#include "ianimation.h"

namespace Gui
{

class ItemFoundAnimation : public IAnimation
{
public:
	ItemFoundAnimation(Location::Model::IItemPtr item, const QRect& locationBound);
	void paint(QPainter& painter) override;
	bool finished() const override;

private:
	int currentX() const;
	QRect currentBound() const;

private:
	const Location::Model::IItemPtr m_item;
	const quint64 m_startTime;
	const int m_direction;
	const QRect m_locationBound;
};

}