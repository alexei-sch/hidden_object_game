#include "converter.h"

namespace Common
{

int Converter::toInt(const QString& str)
{
	bool ok;
	const int res = str.toInt(&ok);
	Q_ASSERT(ok);
	return res;
}

double Converter::toDouble(const QString& str)
{
	bool ok;
	const double res = str.toDouble(&ok);
	Q_ASSERT(ok);
	return res;
}

}