#include "timerview.h"
#include "core/location/timer/itimer.h"
#include "gui/common/timeformatter.h"

namespace Gui
{

TimerView::TimerView(const Location::ITimer& timer, QWidget* parent)
	: QWidget(parent)
	, m_timer(timer)
{
	startTimer(100);
	resize(80, 30);
}

void TimerView::timerEvent(QTimerEvent*)
{
	update();
}

void TimerView::paintEvent(QPaintEvent*)
{
	QPainter painter;
	painter.begin(this);

	painter.setPen(QPen(QBrush(Qt::white), 100));
	painter.setFont(QFont("Tahoma", 14));

	painter.drawText(rect(), Qt::AlignCenter, TimeFormatter::format(m_timer.remaining()));
	painter.end();
}

}