#pragma once
#include "gui/gui.h"

namespace Energy
{
class IEnergyModel;
}

namespace Gui
{

class GUI_EXPORT EnergyWidget : public QWidget
{
	Q_OBJECT

public:
	EnergyWidget(const Energy::IEnergyModel& energy, QWidget* parent);

protected:
	void timerEvent(QTimerEvent*) override;

private:
	Q_SLOT void onUpdated();
	void paintEvent(QPaintEvent*) override;
	QString energy() const;

private:
	const Energy::IEnergyModel& m_energy;
};

}