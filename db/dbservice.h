#pragma once
#include "db/db.h"

namespace DB
{
class IDatabase;

class DB_EXPORT DBService
{
public:
	static void init();
	static void term();

	static IDatabase& db();

private:
	static std::auto_ptr<IDatabase> s_db;
};

}