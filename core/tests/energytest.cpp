#include "energytest.h"
#include "energy/energymodel.h"
#include "db/ienergystorage.h"
#include "energy/energyservice.h"

namespace Tests
{
using namespace Energy;
using namespace DB;

static QDateTime now()
{
	return QDateTime::currentDateTimeUtc();
}

static QDateTime secondsAgo(int secs)
{
	return now().addSecs(secs);
}

void EnergyTest::amountTest1()
{
	EnergyModel model(100, now());
	QCOMPARE(model.amount(), 100);
}

void EnergyTest::amountTest2()
{
	EnergyModel model(50, secondsAgo(-140));
	QCOMPARE(model.amount(), 85);
}

void EnergyTest::amountTest3()
{
	EnergyModel model(0, secondsAgo(-148));
	QCOMPARE(model.amount(), 37);
}

void EnergyTest::amountTest4()
{
	EnergyModel model(90, secondsAgo(-2000));
	QCOMPARE(model.amount(), 100);
}

void EnergyTest::amountTest5()
{
	EnergyModel model(0, secondsAgo(-400));
	QCOMPARE(model.amount(), 100);
}

void EnergyTest::withdrawSuccesTest1()
{
	EnergyModel model(100, now());

	QCOMPARE(model.withdraw(30), true);
	QCOMPARE(model.amount(), 70);
}

void EnergyTest::withdrawSuccesTest2()
{
	EnergyModel model(100, now());

	QCOMPARE(model.withdraw(100), true);
	QCOMPARE(model.amount(), 0);
}

void EnergyTest::withdrawSuccesTest3()
{
	EnergyModel model(20, now());

	QCOMPARE(model.withdraw(19), true);
	QCOMPARE(model.amount(), 1);
}

void EnergyTest::withdrawSuccesTest4()
{
	EnergyModel model(0, now());

	QCOMPARE(model.withdraw(0), true);
	QCOMPARE(model.amount(), 0);
}

void EnergyTest::withdrawSuccesTest5()
{
	EnergyModel model(3, now());

	QCOMPARE(model.withdraw(3), true);
	QCOMPARE(model.amount(), 0);
}

void EnergyTest::withdrawFailTest1()
{
	EnergyModel model(100, now());

	QCOMPARE(model.withdraw(150), false);
	QCOMPARE(model.amount(), 100);
}

void EnergyTest::withdrawFailTest2()
{
	EnergyModel model(30, now());

	QCOMPARE(model.withdraw(35), false);
	QCOMPARE(model.amount(), 30);
}

void EnergyTest::withdrawFailTest3()
{
	EnergyModel model(0, now());

	QCOMPARE(model.withdraw(1), false);
	QCOMPARE(model.amount(), 0);
}

struct TestEnergyStorage : IEnergyStorage
{
	TestEnergyStorage()
		: m_amount(100)
	{
	}
	DB::Energy loadEnergy() const override
	{
		return DB::Energy(m_amount, QDateTime::currentDateTimeUtc());
	}
	void saveEnergy(int amount) override
	{
		m_amount = amount;
	}

	int m_amount;
};

void EnergyTest::energyService1()
{
	TestEnergyStorage es;
	EnergyService::init(es);

	IEnergyModel& model = EnergyService::energy();

	QCOMPARE(model.amount(), 100);

	EnergyService::term(es);
}

void EnergyTest::energyService2()
{
	TestEnergyStorage es;

	{
		EnergyService::init(es);
		IEnergyModel& model = EnergyService::energy();
		QCOMPARE(model.amount(), 100);
		model.withdraw(42);
		QCOMPARE(model.amount(), 58);
		EnergyService::term(es);
	}

	{
		EnergyService::init(es);
		IEnergyModel& model = EnergyService::energy();
		QCOMPARE(model.amount(), 58);
		model.withdraw(42);
		QCOMPARE(model.amount(), 16);
		EnergyService::term(es);
	}

	{
		EnergyService::init(es);
		IEnergyModel& model = EnergyService::energy();
		QCOMPARE(model.amount(), 16);
		model.withdraw(16);
		QCOMPARE(model.amount(), 0);
		EnergyService::term(es);
	}

	{
		EnergyService::init(es);
		IEnergyModel& model = EnergyService::energy();
		QCOMPARE(model.amount(), 0);
		QCOMPARE(model.withdraw(10), false);
		QCOMPARE(model.amount(), 0);
		EnergyService::term(es);
	}
}

}