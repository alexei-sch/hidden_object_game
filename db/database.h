#pragma once
#include "idatabase.h"

namespace DB
{

class Database : public IDatabase
{
public:
	Database();
	~Database();

	Energy loadEnergy() const override;
	void saveEnergy(int amount) override;

	void saveRecord(int locationId, int seconds) override;
	bool emptyRecord(int locationId) const override;
	int bestRecord(int locationId) const override;

private:
	QSqlDatabase m_db;
};

}