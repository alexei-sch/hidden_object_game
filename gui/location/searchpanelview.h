#pragma once
#include "core/location/model/iitemmodel.h"

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

class SearchPanelView : public QWidget
{
	Q_OBJECT

public:
	SearchPanelView(const Location::Model::ILocationModel& model, QWidget* parent);

protected:
	void paintEvent(QPaintEvent*) override;

private:
	void drawItems(QPainter& painter);
	Q_SLOT void onItemFound(IItemPtr);

private:
	const Location::Model::ILocationModel& m_model;
};

}