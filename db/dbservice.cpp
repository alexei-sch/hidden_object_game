#include "dbservice.h"
#include "database.h"

namespace DB
{
std::auto_ptr<IDatabase> DBService::s_db;

void DBService::init()
{
	Q_ASSERT(s_db.get() == NULL);
	s_db.reset(new Database());
}

void DBService::term()
{
	Q_ASSERT(s_db.get() != NULL);
	s_db.reset();
}

IDatabase& DBService::db()
{
	Q_ASSERT(s_db.get() != NULL);
	return *s_db;
}

}