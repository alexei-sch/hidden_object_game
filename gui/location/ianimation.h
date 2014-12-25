#pragma once

namespace Gui
{

class IAnimation
{
public:
	virtual ~IAnimation() {};

	virtual void paint(QPainter& painter) = 0;
	virtual bool finished() const = 0;
};

}