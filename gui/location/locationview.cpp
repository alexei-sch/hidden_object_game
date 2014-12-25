#include "locationview.h"
#include "resources/resourceprovider.h"
#include "resources/ilocationresourceprovider.h"
#include "core/location/model/ilocationmodel.h"
#include "core/location/model/itemsmodel.h"
#include "itemfoundanimation.h"

namespace Gui
{
using namespace std;
using namespace Resources;
using namespace Location;
using namespace Location::Model;

LocationView::LocationView(const ILocationModel& model, const LocationId& locationId, QWidget* parent)
	: QWidget(parent)
	, m_model(model)
	, m_backgroundImage(ResourceProvider::location(locationId)->backgroundImage())
{
	connect(&m_model, SIGNAL(itemFound(IItemPtr)), SLOT(onItemFound(IItemPtr)));
	connect(&m_animations, SIGNAL(animationsUpdated()), SLOT(onAnimationsUpdated()));

	resize(m_backgroundImage.size());
}

void LocationView::paintEvent(QPaintEvent*)
{
	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.drawImage(0, 0, m_backgroundImage);
	drawItems(painter);
	m_animations.process(painter);

	painter.end();
}

void LocationView::drawItems(QPainter &painter)
{
	for(int i = 0; i < m_model.activeItems().count(); ++i)
	{
		const IItem& item = m_model.activeItems().item(i);
		painter.drawImage(item.position(), item.image());
	}
}

void LocationView::onItemFound(IItemPtr item)
{
	m_animations.add(auto_ptr<IAnimation>(new ItemFoundAnimation(item, rect())));
	update();
}

void LocationView::onAnimationsUpdated()
{
	update();
}

}