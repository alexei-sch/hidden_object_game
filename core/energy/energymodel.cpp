#include "energymodel.h"

namespace Energy
{

static const int s_energyMax = 100;
//! Recovers per second
static const double s_recoverySpeed = 0.25;


EnergyModel::EnergyModel(int initialAmount, const QDateTime& lastUpdateTimeUTC)
	: m_lastAmount(initialAmount)
	, m_lastUpdateTimeUTC(lastUpdateTimeUTC)
{
	Q_ASSERT(m_lastAmount >= 0);
}

static int limit(int amount)
{
	return qMin(amount, s_energyMax);
}

int EnergyModel::amount() const 
{
	return limit(m_lastAmount + s_recoverySpeed * elapsedInSeconds());
}

int EnergyModel::elapsedInSeconds() const
{
	return QDateTime::currentDateTimeUtc().toTime_t() - m_lastUpdateTimeUTC.toTime_t();
}

bool EnergyModel::withdraw(int value)
{
	if (amount() < value)
	{
		return false;
	}

	updateAmount(amount() - value);

	return true;
}

void EnergyModel::updateAmount(int value)
{
	Q_ASSERT(value >= 0);

	m_lastAmount = value;
	m_lastUpdateTimeUTC = QDateTime::currentDateTimeUtc();

	Q_EMIT updated();
}

}