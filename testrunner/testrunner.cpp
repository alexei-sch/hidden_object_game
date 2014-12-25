#include "testrunner.h"

namespace Tests
{
using namespace std;
using namespace std::tr1;

static Modules loadModules(const ModuleNames& moduleNames)
{
	Modules modules;
	Q_FOREACH(const QString& moduleName, moduleNames)
	{
		try
		{
			modules << shared_ptr<TestModule>(new TestModule(moduleName));
		}
		catch(const InvalidTestModule& e)
		{
			cout << "Error during test module loading occured: " << e.what() << endl;
		}
	}
	return modules;
}

TestRunner::TestRunner(const ModuleNames& moduleNames)
	: m_modules(loadModules(moduleNames))
{
}

void printStatistics(int failed)
{
	if (failed != 0)
	{
		cout << "Some tests failed. Total failers: " << failed << endl;
	}
	else
	{
		cout << "All tests passed" << endl;
	}
	cout << endl << endl;
}

static int runModuleTests(TestModule& module)
{
	cout << "------------ Start testing module:" << module.name().toStdString() << " ------------" << endl;

	const int  currentFailed = module.runAll();

	printStatistics(currentFailed);

	return currentFailed;
}

int TestRunner::runAll() const
{
	int totalFailed = 0;

	Q_FOREACH(shared_ptr<TestModule> module, m_modules)
	{
		totalFailed += runModuleTests(*module);
	}

	cout << "\n\n\n******************** SUMMARY ************************" << endl;
	printStatistics(totalFailed);
	return totalFailed;
}

}