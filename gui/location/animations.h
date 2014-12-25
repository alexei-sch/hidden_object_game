#pragma once

namespace Gui
{
class IAnimation;

class Animations : public QObject
{
	Q_OBJECT

public:
	void add(std::auto_ptr<IAnimation> animation);
	void process(QPainter& painter);

	Q_SIGNAL void animationsUpdated();

protected:
	void timerEvent(QTimerEvent*) override;

private:
	void paintAnimations(QPainter& painter);
	void removeFinishedAnimations();

private:
	typedef std::tr1::shared_ptr<IAnimation> IAnimationPtr;
	QList<IAnimationPtr> m_animations;
	int m_timer;
};

}
