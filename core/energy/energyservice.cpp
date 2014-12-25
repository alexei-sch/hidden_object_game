#include "energyservice.h"
#include "energymodel.h"
#include "db/ienergystorage.h"
#include "db/energy.h"
#include "db/dbservice.h"

namespace Energy
{
std::auto_ptr<IEnergyModel> EnergyService::s_model;

void EnergyService::init(DB::IEnergyStorage& storage)
{
	Q_ASSERT(s_model.get() == NULL);
	
	const DB::Energy energy = storage.loadEnergy();
	s_model.reset(new EnergyModel(energy.amount, energy.updateTime));
}

void EnergyService::term(DB::IEnergyStorage& storage)
{
	Q_ASSERT(s_model.get() != NULL);

	storage.saveEnergy(s_model->amount());
	s_model.reset();
}

IEnergyModel& EnergyService::energy()
{
	Q_ASSERT(s_model.get() != NULL);
	return *s_model;
}

}