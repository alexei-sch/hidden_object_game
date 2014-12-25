#pragma once
#include "gui/gui.h"

namespace Gui
{
namespace Dialogs
{

class GUI_EXPORT Dialog : public QDialog
{
	Q_OBJECT

public:
	virtual ~Dialog() {};

	Dialog(const QString& text, const QString& okButtonText, const QString& cancelButtonText = "");
};

}
}