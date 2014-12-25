#pragma once
#include "ienergymodel.h"

namespace Energy
{

class EnergyModel : public IEnergyModel
{
public:
	EnergyModel(int initialAmount, const QDateTime& lastUpdateTimeUTC);

	int amount() const override;
	bool withdraw(int value) override;

private:
	int elapsedInSeconds() const;
	void updateAmount(int value);

private:
	int m_lastAmount;
	QDateTime m_lastUpdateTimeUTC;
};

}