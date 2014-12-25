#include "mainscreenwidget.h"
#include "resources/resourceprovider.h"
#include "stickerbutton.h"
#include "dialogs/idialogmanager.h"
#include "locationinfodialog.h"

namespace Gui
{
using namespace std;
using namespace Resources;
using namespace Location;
using namespace DB;
using namespace Dialogs;

MainScreenWidget::MainScreenWidget(Dialogs::IDialogManager& dialogManager, const IRecordsStorage& recordsStorage, QWidget* parent)
	: QWidget(parent)
	, m_dialogManager(dialogManager)
	, m_background(ResourceProvider::mainscreenBack())
	, m_closeButton(new CloseButton(this))
	, m_recordsStorage(recordsStorage)
{
	resize(m_background.size());
	addStickerButton(LocationId(1), QPoint(250, 370));
	addStickerButton(LocationId(2), QPoint(255, 245));

	m_closeButton->move((size().width() - m_closeButton->width()) / 2, size().height() - m_closeButton->height());
	connect(m_closeButton.get(), SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
}

void MainScreenWidget::paintEvent(QPaintEvent*)
{
	QPainter painter;
	painter.begin(this);

	painter.drawImage(0, 0, m_background);

	painter.end();
}

void MainScreenWidget::addStickerButton(const LocationId& id, const QPoint& point)
{
	//no leak here
	QWidget* button = new StickerButton(id, this);
	button->move(point);
	connect(button, SIGNAL(clicked(const LocationId&)), SLOT(onStickerButtonCLicked(const LocationId&)));
}

void MainScreenWidget::onStickerButtonCLicked(const LocationId& id)
{
	auto_ptr<LocationInfoDialog> dialog(new LocationInfoDialog(id, m_recordsStorage));

	connect(dialog.get(), SIGNAL(showLocation(const LocationId&)), SIGNAL(showLocation(const LocationId&)));

	m_dialogManager.showDialog(auto_ptr<Dialog>(dialog.release()));
}

}