#pragma once

namespace Energy
{

class IEnergyModel : public QObject
{
	Q_OBJECT

public:
	virtual int amount() const = 0;
	virtual bool withdraw(int value) = 0;

public:
	Q_SIGNAL void updated();
};

}