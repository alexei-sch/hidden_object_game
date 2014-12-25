#pragma once

namespace Common
{

struct Converter
{
	static int toInt(const QString& str);
	static double toDouble(const QString& str);
};

}