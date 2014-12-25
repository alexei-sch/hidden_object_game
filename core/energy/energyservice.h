#pragma once
#include "core/core.h"

namespace DB
{
class IEnergyStorage;
}

namespace Energy
{
class IEnergyModel;

class CORE_EXPORT EnergyService
{
public:
	static void init(DB::IEnergyStorage& storage);
	static void term(DB::IEnergyStorage& storage);

	static IEnergyModel& energy();

private:
	static std::auto_ptr<IEnergyModel> s_model;
};

}