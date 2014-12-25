#pragma once
#include "energy.h"

namespace DB
{

class IEnergyStorage
{
public:
	virtual Energy loadEnergy() const = 0;
	virtual void saveEnergy(int amount) = 0;
};

}