#pragma once
#include "core/core.h"
#include "core/location/timer/itimer.h"

namespace Location
{

class Timer : public ITimer
{
public:
	Timer();

	void start() override;
	void stop() override;

	int elapsed() const override;
	int remaining() const override;

private:
	int currentElapsed() const;

private:
	enum State
	{
		started,
		stopped
	};

private:
	int m_totalElapsed;
	uint m_start;
	State m_state;
};

}