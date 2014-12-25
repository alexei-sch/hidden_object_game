#pragma once

namespace Location
{
class ITimer;
}

namespace Gui
{

class TimerView : public QWidget
{
	Q_OBJECT

public:
	TimerView(const Location::ITimer& timer, QWidget* parent);

protected:
	void timerEvent(QTimerEvent*) override;
	void paintEvent(QPaintEvent*) override;

private:
	QString time() const;

private:
	const Location::ITimer& m_timer;
};

}