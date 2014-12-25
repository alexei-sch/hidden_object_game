#include "gamewidget.h"
#include "location/locationview.h"
#include "location/locationcontroller.h"
#include "location/searchpanelview.h"
#include "location/timerview.h"
#include "common/closebutton.h"
#include "core/game/igamemodel.h"
#include "gui/common/timeformatter.h"
#include "gui/dialogs/idialogmanager.h"

namespace Gui
{
using namespace std;
using namespace Dialogs;
using namespace Game;
using namespace Location;

GameWidget::GameWidget(IGameModel& game, Dialogs::IDialogManager& dialogManager, QWidget* parent)
	: QWidget(parent)
	, m_game(game)
	, m_dialogManager(dialogManager)
	, m_locationView(new LocationView(game.location(), game.id(), this))
	, m_locationController(new LocationController(game.location()))
	, m_searchPanelView(new SearchPanelView(game.location(), this))
	, m_timerView(new TimerView(game.timer(), this))
	, m_closeButton(new CloseButton(this))
{
	resize(QSize(m_locationView->width(), 1024));

	m_timerView->move((size().width() - m_timerView->width()) / 2, 0);

	m_searchPanelView->resize(m_locationView->width(), 100);
	m_searchPanelView->move(0, m_locationView->rect().bottom());

	m_closeButton->move(size().width() - m_closeButton->width(), 0);
	connect(m_closeButton.get(), SIGNAL(clicked()), SIGNAL(closed()));

	connect(&m_game, SIGNAL(win(bool,int)), SLOT(onGameWin(bool,int)));
}

GameWidget::~GameWidget()
{
}

void GameWidget::mousePressEvent(QMouseEvent* event)
{
	m_locationController->mousePressEvent(event);
}

static QString winMessage(bool newRecord, int time)
{
	if (newRecord)
	{
		return QString("New world record: <b>%1</b>!").arg(TimeFormatter::format(time));
	}
	else
	{
		return QString("It was amazing - <b>%1</b>").arg(TimeFormatter::format(time));
	}
}

void GameWidget::onGameWin(bool newRecord, int time)
{
	auto_ptr<Dialog> dialog(new Dialog(winMessage(newRecord, time), "cool"));
	connect(dialog.get(), SIGNAL(accepted()), SIGNAL(closed()));
	connect(dialog.get(), SIGNAL(rejected()), SIGNAL(closed()));

	m_dialogManager.showDialog(dialog);
}

}