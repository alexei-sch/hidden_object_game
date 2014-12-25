#include "timeformatter.h"

namespace Gui
{

static QString zeroPad(int value)
{
	Q_ASSERT(value >= 0);

	QString str = QString::number(value);
	return (value < 10) ? str.prepend("0") : str;
}

QString TimeFormatter::format(int timeInSecs)
{
	const int minutes = timeInSecs / 60;
	const int seconds = timeInSecs % 60;
	return zeroPad(minutes) + ":" + zeroPad(seconds);
}

}