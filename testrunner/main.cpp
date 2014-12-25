#include "testrunner.h"
using namespace Tests;

static ModuleNames modulesFromParameters(int argc, char* argv[])
{
	argc;argv;
	return ModuleNames() << "db.dll" << "core.dll";
}

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);

	TestRunner runner(modulesFromParameters(argc, argv));

	return runner.runAll();
}
