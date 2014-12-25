#pragma once
#include "core/core.h"
#include "core/game/igamemodel.h"
#include "core/location/model/ilocationmodel.h"
#include "core/location/timer/itimer.h"
#include "core/location/model/iitemmodel.h"

namespace DB
{
class IRecordsStorage;
}

namespace Game
{
using Location::Model::IItemPtr;

class CORE_EXPORT GameModel : public IGameModel
{
	Q_OBJECT

public:
	GameModel(const Location::LocationId& id, DB::IRecordsStorage& recordsStorage);

	const Location::LocationId& id() const override;
	Location::Model::ILocationModel& location() const override;
	const Location::ITimer& timer() const override;

private:
	bool saveRecord() const;

private:
	Q_SLOT void onItemFound(IItemPtr);

private:
	const Location::LocationId m_id;
	std::auto_ptr<Location::Model::ILocationModel> m_locationModel;
	std::auto_ptr<Location::ITimer> m_timer;
	DB::IRecordsStorage& m_recordsStorage;
};

}