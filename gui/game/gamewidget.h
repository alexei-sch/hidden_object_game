#pragma once
#include "gui/gui.h"
#include "core/game/igamemodel.h"

namespace Gui
{
class LocationView;
class LocationController;
class SearchPanelView;
class TimerView;
class CloseButton;
namespace Dialogs
{
class IDialogManager;
}

class GUI_EXPORT GameWidget : public QWidget
{
	Q_OBJECT

public:
	GameWidget(Game::IGameModel& game, Dialogs::IDialogManager& dialogManager, QWidget* parent);
	~GameWidget();

public:
	Q_SIGNAL void closed();

protected:
	void mousePressEvent(QMouseEvent* event) override;

private:
	Q_SLOT void onGameWin(bool newRecord, int time);
	void drawLocation(QPainter& painter);

private:
	std::auto_ptr<Gui::LocationView> m_locationView;
	std::auto_ptr<Gui::LocationController> m_locationController;
	std::auto_ptr<Gui::SearchPanelView> m_searchPanelView;
	std::auto_ptr<Gui::TimerView> m_timerView;
	std::auto_ptr<Gui::CloseButton> m_closeButton;

	Game::IGameModel& m_game;
	Dialogs::IDialogManager& m_dialogManager;
};

}