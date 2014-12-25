#include "dialog.h"

namespace Gui
{
namespace Dialogs
{

Dialog::Dialog(const QString& text, const QString& okButtonText, const QString& cancelButtonText)
	: QDialog(NULL, Qt::FramelessWindowHint)
{
	//no leaks here

	resize(200, 100);
	QLabel* label = new QLabel(text, this);

	QGridLayout* layout = new QGridLayout(this);
	setLayout(layout);

	QPushButton* okButton = new QPushButton(okButtonText, this);
	connect(okButton, SIGNAL(clicked()), SIGNAL(accepted()));

	
	QPushButton* cancelButton = NULL;
	if (!cancelButtonText.isEmpty())
	{
		cancelButton = new QPushButton(cancelButtonText, this);
		connect(cancelButton, SIGNAL(clicked()), SIGNAL(rejected()));
	}

	layout->addWidget(label, 0, 0, 1, 0, Qt::AlignCenter);

	if (!cancelButtonText.isEmpty())
	{
		layout->addWidget(okButton, 1, 0);
		layout->addWidget(cancelButton, 1, 1);
	}
	else
	{
		layout->addWidget(okButton, 1, 0, 1, 0);
	}
}

}
}