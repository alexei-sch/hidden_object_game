#pragma once
#include "core/location/locationid.h"
#include "core/location/model/iitemmodel.h"
#include "gui/location/animations.h"


namespace Location
{
namespace Model
{
class ILocationModel;
}
}

namespace Gui
{
using Location::Model::IItemPtr;

class LocationView : public QWidget
{
	Q_OBJECT

public:
	LocationView(const Location::Model::ILocationModel& model, const Location::LocationId& locationId, QWidget* parent);

protected:
	void paintEvent(QPaintEvent*) override;

private:
	Q_SLOT void onItemFound(IItemPtr item);
	Q_SLOT void onAnimationsUpdated();

	void drawItems(QPainter& painter);

private:
	const Location::Model::ILocationModel& m_model;
	const QImage m_backgroundImage;

	Animations m_animations;
};

}