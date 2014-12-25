#pragma once

namespace Tests
{

class DBTest : public QObject
{
	Q_OBJECT

public:
	Q_INVOKABLE DBTest() {};

private:
	Q_SLOT void initTestCase();
	Q_SLOT void cleanupTestCase();

	Q_SLOT void open();
	Q_SLOT void selectEnergy();
};

}