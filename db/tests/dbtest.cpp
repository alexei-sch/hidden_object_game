#include "dbtest.h"
#include "database.h"
#include "dbservice.h"

namespace Tests
{
using namespace DB;

void DBTest::initTestCase()
{
	DBService::init();
}

void DBTest::cleanupTestCase()
{
	DBService::term();
}

void DBTest::open()
{
	IDatabase& db = DBService::db();
	db;
}

void DBTest::selectEnergy()
{
	DBService::db().saveEnergy(30);
	const Energy energy = DBService::db().loadEnergy();

	QCOMPARE(energy.amount, 30);
	QCOMPARE(energy.updateTime.toTime_t(), QDateTime::currentDateTime().toTime_t());
}

}