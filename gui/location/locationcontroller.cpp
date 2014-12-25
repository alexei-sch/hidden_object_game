#include "locationcontroller.h"
#include "core/location/model/ilocationmodel.h"

namespace Gui
{

LocationController::LocationController(Location::Model::ILocationModel& model)
	: m_model(model)
{
}

void LocationController::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_model.guess(event->posF());
	}
}

}