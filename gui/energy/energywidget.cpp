#include "energywidget.h"
#include "core/energy/ienergymodel.h"

namespace Gui
{
using namespace Energy;

EnergyWidget::EnergyWidget(const IEnergyModel& energy, QWidget* parent)
	: QWidget(parent)
	, m_energy(energy)
{
	connect(&m_energy, SIGNAL(updated()), SLOT(onUpdated()));
	startTimer(100);
}

void EnergyWidget::onUpdated()
{
	update();
}

void EnergyWidget::paintEvent(QPaintEvent*)
{
	QPainter painter;
	painter.begin(this);
	painter.setPen(QPen(QBrush(Qt::darkGreen), 100));
	painter.setFont(QFont("Tahoma", 14));

	painter.drawText(rect(), Qt::AlignCenter, energy());

	painter.end();
}

QString EnergyWidget::energy() const
{
	return QString("Energy: %1").arg(m_energy.amount());
}

void EnergyWidget::timerEvent(QTimerEvent*)
{
	update();
}

}