#pragma once
#include "gui/gui.h"
#include "core/location/locationid.h"
#include "gui/common/closebutton.h"
#include "gui/mainscreen/locationinfodialog.h"

namespace DB
{
class IRecordsStorage;
}

namespace Gui
{
using Location::LocationId;
namespace Dialogs
{
class IDialogManager;
}

class GUI_EXPORT MainScreenWidget : public QWidget
{
	Q_OBJECT

public:
	MainScreenWidget(Dialogs::IDialogManager& dialogManager, const DB::IRecordsStorage& recordsStorage, QWidget* parent);

public:
	Q_SIGNAL void showLocation(const LocationId& id);

protected:
	void paintEvent(QPaintEvent*) override;

private:
	void addStickerButton(const LocationId& id, const QPoint& point);
	Q_SLOT void onStickerButtonCLicked(const LocationId& id);

private:
	 const QImage m_background;
	 std::auto_ptr<Gui::CloseButton> m_closeButton;
	 Dialogs::IDialogManager& m_dialogManager;
	 const DB::IRecordsStorage& m_recordsStorage;
};

}