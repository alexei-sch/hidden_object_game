#pragma once
///#include "energy.h"

namespace DB
{

class IRecordsStorage
{
public:
	virtual void saveRecord(int locationId, int seconds) = 0;

	virtual int bestRecord(int locationId) const = 0;
	virtual bool emptyRecord(int locationId) const = 0;
};

}