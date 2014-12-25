#include "testmodule.h"

namespace Tests
{
using namespace std;

typedef TestObjects (*TestFunction)();
static const char* s_testFunctionName = TEST_FUNCTION_NAME_STR;

TestModule::TestModule(const QString& moduleName)
	: m_library(moduleName)
{
	if (!m_library.load())
	{
		throw InvalidTestModule(moduleName, m_library.errorString());
	}

	TestFunction testFunction = static_cast<TestFunction>(m_library.resolve(s_testFunctionName));
	if (testFunction == 0)
	{
		throw InvalidTestModule(moduleName, m_library.errorString());
	}

	m_testMetaObjects = testFunction();
}

int TestModule::runAll()
{
	int totalFailed = 0;
	for(int i = 0; i < m_testMetaObjects.count; ++i)
	{
		QMetaObjectPtr testMetaObject = m_testMetaObjects.array[i];
		auto_ptr<QObject> testObject(testMetaObject->newInstance());
		totalFailed += QTest::qExec(testObject.get());
	}
	return totalFailed;
}

QString TestModule::name() const
{
	return m_library.fileName();
}

}