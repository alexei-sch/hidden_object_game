#pragma once
#include "testmodule.h"

namespace Tests
{
typedef QList<QString> ModuleNames;
typedef QList<std::tr1::shared_ptr<TestModule>> Modules;

class TestRunner
{
public:
	TestRunner(const ModuleNames& moduleNames);
	int runAll() const;

private:
	Modules m_modules;
};

}
