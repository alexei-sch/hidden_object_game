#pragma once
#include "gui/gui.h"
#include "idialogmanager.h"

namespace Gui
{
namespace Dialogs
{

class GUI_EXPORT DialogManager 
	: public QWidget
	, public IDialogManager
{
	Q_OBJECT

public:
	DialogManager(QWidget* parent);

	void showDialog(std::auto_ptr<Dialog> dialog) override;

protected:
	bool eventFilter(QObject* obj, QEvent* event) override;

private:
	void showDialogInternal();
	void showOverlay();
	Q_SLOT void hideDialog();

private:
	std::auto_ptr<Dialog> m_dialog;
	std::auto_ptr<QWidget> m_overlay;
};

}
}