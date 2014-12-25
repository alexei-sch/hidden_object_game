#pragma once

namespace Tests
{

class EnergyTest : public QObject
{
	Q_OBJECT

public:
	Q_INVOKABLE EnergyTest() {};

private:
	Q_SLOT void amountTest1();
	Q_SLOT void amountTest2();
	Q_SLOT void amountTest3();
	Q_SLOT void amountTest4();
	Q_SLOT void amountTest5();

	Q_SLOT void withdrawSuccesTest1();
	Q_SLOT void withdrawSuccesTest2();
	Q_SLOT void withdrawSuccesTest3();
	Q_SLOT void withdrawSuccesTest4();
	Q_SLOT void withdrawSuccesTest5();

	Q_SLOT void withdrawFailTest1();
	Q_SLOT void withdrawFailTest2();
	Q_SLOT void withdrawFailTest3();

	Q_SLOT void energyService1();
	Q_SLOT void energyService2();
};

}