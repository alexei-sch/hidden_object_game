#include "timer.h"

namespace Location
{
static const int s_max = 5 * 60;//secs

Timer::Timer()
	: m_totalElapsed(0)
	, m_state(stopped)
{
}

void Timer::start()
{
	Q_ASSERT(m_state == stopped);
	m_state = started;

	m_start = QDateTime::currentDateTimeUtc().toTime_t();
}

void Timer::stop()
{
	Q_ASSERT(m_state == started);

	m_totalElapsed += currentElapsed();

	m_state = stopped;
}

int Timer::elapsed() const 
{
	return m_totalElapsed + currentElapsed();
}

int Timer::currentElapsed() const
{
	return m_state == started ? 
		QDateTime::currentDateTimeUtc().toTime_t() - m_start :
		0;
}

int Timer::remaining() const 
{
	return qMax(s_max - elapsed(), 0);
}

}