#pragma once
#include "gui/dialogs/dialog.h"

namespace Gui
{
namespace Dialogs
{

class IDialogManager
{
public:
	virtual ~IDialogManager() {}

	virtual void showDialog(std::auto_ptr<Dialog> dialog) = 0;
};

}
}