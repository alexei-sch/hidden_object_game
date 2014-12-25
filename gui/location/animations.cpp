#include "animations.h"
#include "ianimation.h"
#include <algorithm>

namespace Gui
{

void Animations::add(std::auto_ptr<IAnimation> animation)
{
	if (m_animations.empty())
	{
		m_timer = startTimer(10);
	}

	m_animations << IAnimationPtr(animation);
}

void Animations::process(QPainter& painter)
{
	paintAnimations(painter);
	removeFinishedAnimations();
}

void Animations::paintAnimations(QPainter& painter)
{
	Q_FOREACH(IAnimationPtr animation, m_animations)
	{
		animation->paint(painter);
	}
}

void Animations::removeFinishedAnimations()
{
	m_animations.erase(
		std::remove_if(m_animations.begin(), m_animations.end(), std::tr1::bind(&IAnimation::finished, std::tr1::placeholders::_1)), 
		m_animations.end());

	if (m_animations.empty() &&
		m_timer > 0)
	{
		killTimer(m_timer);
		m_timer = -1;
	}
}

void Animations::timerEvent(QTimerEvent*)
{
	Q_EMIT animationsUpdated();
}


}