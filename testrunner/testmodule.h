#pragma once
#include "public.h"

namespace Tests
{

class InvalidTestModule : public std::runtime_error
{
public:
	InvalidTestModule(const QString& moduleName, const QString& reason)
		: std::runtime_error(QString("Failed to load module: %1, reason: %2").arg(moduleName).arg(reason).toStdString())
	{}
};

class TestModule
{
private:
	TestModule();

public:
	//! throws InvalidTestModule exception
	TestModule(const QString& moduleName);
	int runAll();
	QString name() const;

private:
	QLibrary m_library;
	TestObjects m_testMetaObjects;
};


}