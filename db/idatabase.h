#pragma once
#include "ienergystorage.h"
#include "irecordsstorage.h"

namespace DB
{

class IDatabase 
	: public IEnergyStorage
	, public IRecordsStorage
{
public:
	virtual ~IDatabase() {};
};

}