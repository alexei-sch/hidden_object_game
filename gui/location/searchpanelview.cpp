#include "searchpanelview.h"
#include "core/location/model/ilocationmodel.h"
#include "core/location/model/itemsmodel.h"

namespace Gui
{
using namespace Location;
using namespace Location::Model;

SearchPanelView::SearchPanelView(const Location::Model::ILocationModel& model, QWidget* parent)
	: QWidget(parent)
	, m_model(model)
{
	resize(500, 50);

	connect(&m_model, SIGNAL(itemFound(IItemPtr)), SLOT(onItemFound(IItemPtr)));
}

void SearchPanelView::paintEvent(QPaintEvent*)
{
	QPainter painter;
	painter.begin(this);

	drawItems(painter);

	painter.end();
}

void SearchPanelView::drawItems(QPainter& painter)
{
	int totalWidth = 0;
	for(int i = 0; i < m_model.activeItems().count(); ++i)
	{
		const QImage& item = m_model.activeItems().item(i).imageForSearchPanel();

		painter.drawImage(QPoint(totalWidth, 20), item);

		totalWidth += item.width() + 5;
	}
}

void SearchPanelView::onItemFound(IItemPtr)
{
	update();
}

}