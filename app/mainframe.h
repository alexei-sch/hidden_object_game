#pragma once
#include "core/game/gamemodel.h"
#include "gui/game/gamewidget.h"
#include "gui/energy/energywidget.h"
#include "gui/mainscreen/mainscreenwidget.h"
#include "core/location/locationid.h"
#include "gui/dialogs/idialogmanager.h"

namespace DB
{
class IDatabase;
}

namespace Energy
{
class IEnergyModel;
}

namespace Gui
{
using Location::LocationId;

class MainFrame : public QWidget
{
	Q_OBJECT

public:
	MainFrame(DB::IDatabase& db, Energy::IEnergyModel& energy);
	Q_SLOT void startMainScreen();

private:
	Q_SLOT void tryStartNewGame(const LocationId& id);
	void startNewGame(const LocationId& id);
	void showWidget(QWidget* widget);

private:
	struct EnergyItem
	{
		EnergyItem(Energy::IEnergyModel& model, QWidget* parent);

		std::auto_ptr<EnergyWidget> widget;
		Energy::IEnergyModel& model;
	};

	struct GameItem
	{
		GameItem(const Location::LocationId& id, DB::IRecordsStorage& recordsStorage,
				 Dialogs::IDialogManager& dialogManager, QWidget* parent);

		std::auto_ptr<Game::IGameModel> model;
		std::auto_ptr<GameWidget> widget;
	};

private:
	DB::IDatabase& m_db;
	EnergyItem m_energy;

	std::auto_ptr<MainScreenWidget> m_mainScreen;
	std::auto_ptr<GameItem> m_game;

	std::auto_ptr<Dialogs::IDialogManager> m_dialogManager;
};

}