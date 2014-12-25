#pragma once

namespace Location
{

class ITimer
{
public:
	virtual ~ITimer() {}

	virtual void start() = 0;
	virtual void stop() = 0;

	virtual int elapsed() const = 0;
	virtual int remaining() const = 0;
};

}