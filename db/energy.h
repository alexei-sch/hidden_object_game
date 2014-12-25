#pragma once

namespace DB
{

struct Energy
{
	Energy(int amount, const QDateTime& updateTime)
		: amount(amount)
		, updateTime(updateTime)
	{
		Q_ASSERT(amount >= 0);
		Q_ASSERT(updateTime.isValid());
	}

	const int amount;
	const QDateTime updateTime;
};

}