#include "dialogmanager.h"
#include "dialog.h"

namespace Gui
{
namespace Dialogs
{

DialogManager::DialogManager(QWidget* parent)
	: QWidget(parent)
{
}


void DialogManager::showDialog(std::auto_ptr<Dialog> dialog)
{
	resize(parentWidget()->size());

	m_dialog = dialog;

	showDialogInternal();
	showOverlay();

	show();
	raise();
}

void DialogManager::showDialogInternal()
{
	Q_ASSERT(m_dialog.get());

	connect(m_dialog.get(), SIGNAL(rejected()), SLOT(hideDialog()));
	connect(m_dialog.get(), SIGNAL(accepted()), SLOT(hideDialog()));
	m_dialog->move((width() - m_dialog->width()) / 2, (height() - m_dialog->height()) / 2);
	m_dialog->show();
}

void DialogManager::showOverlay()
{
	m_overlay.reset(new QWidget(this));
	m_overlay->resize(size());

	QPalette pal(m_overlay->palette());
	pal.setColor(QPalette::Background, QColor(0, 0, 0, 150));
	m_overlay->setAutoFillBackground(true);
	m_overlay->setPalette(pal);

	m_overlay->show();
	m_overlay->installEventFilter(this);
}

bool DialogManager::eventFilter(QObject*, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		if (m_dialog.get())
		{
			m_dialog->reject();
		}
		hideDialog();
		return true;
	}
	return false;
}

void DialogManager::hideDialog()
{
	m_dialog.reset();
	m_overlay.reset();
	hide();
}

}
}