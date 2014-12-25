#pragma once
#include "core/location/locationid.h"

namespace Location
{
namespace Model
{
class ILocationModel;
}
class ITimer;
}

namespace Game
{

class IGameModel : public QObject
{
	Q_OBJECT

public:
	virtual ~IGameModel() {};

	virtual const Location::LocationId& id() const = 0;
	virtual Location::Model::ILocationModel& location() const = 0;
	virtual const Location::ITimer& timer() const = 0;

public:
	Q_SIGNAL void win(bool newRecord, int time);
};

}