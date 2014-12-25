#pragma once

namespace Location
{
namespace Model
{
class ILocationModel;
}
}

namespace Gui
{

class LocationController
{
public:
	LocationController(Location::Model::ILocationModel& model);
	void mousePressEvent(QMouseEvent* event);

private:
	Location::Model::ILocationModel& m_model;
};

}