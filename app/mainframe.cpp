#include "mainframe.h"
#include "db/idatabase.h"
#include "core/energy/ienergymodel.h"
#include "gui/dialogs/dialogmanager.h"

namespace Gui
{
using namespace std;
using namespace DB;
using namespace Location;
using namespace Game;
using namespace Energy;
using namespace Dialogs;

MainFrame::MainFrame(IDatabase& db, IEnergyModel& energy)
	: m_db(db)
	, m_energy(energy, this)
	, m_dialogManager(new DialogManager(this))
{
}

void MainFrame::startMainScreen()
{
	m_game.reset();

	m_mainScreen.reset(new MainScreenWidget(*m_dialogManager, m_db, this));
	connect(m_mainScreen.get(), SIGNAL(showLocation(const LocationId&)), SLOT(tryStartNewGame(const LocationId&)), Qt::QueuedConnection);

	showWidget(m_mainScreen.get());
}

void MainFrame::tryStartNewGame(const Location::LocationId& id)
{
	static const int s_gameCost = 10;
	if (!m_energy.model.withdraw(s_gameCost))
	{
		m_dialogManager->showDialog(auto_ptr<Dialog>(new Dialog("not enough energy, dude...", "so sad")));
		return;
	}

	startNewGame(id);
}

void MainFrame::startNewGame(const LocationId& id)
{
	m_mainScreen.reset();

	m_game.reset(new GameItem(id, m_db, *m_dialogManager, this));
	connect(m_game->widget.get(), SIGNAL(closed()), SLOT(startMainScreen()), Qt::QueuedConnection);

	showWidget(m_game->widget.get());
}

void MainFrame::showWidget(QWidget* widget)
{
	const int x = (width() - widget->width()) / 2;
	m_energy.widget->move(x, 0);
	widget->move(x, 30);
	widget->show();
}

//////////////////////////////////////////////////////////////////////////
// some helpers
MainFrame::EnergyItem::EnergyItem(IEnergyModel& model, QWidget* parent)
	: model(model)
{
	widget.reset(new EnergyWidget(model, parent));
}


MainFrame::GameItem::GameItem(const Location::LocationId& id, 
							  DB::IRecordsStorage& recordsStorage, 
							  Dialogs::IDialogManager& dialogManager, QWidget* parent)
{
	model.reset(new GameModel(id, recordsStorage));
	widget.reset(new GameWidget(*model, dialogManager, parent));
}
}