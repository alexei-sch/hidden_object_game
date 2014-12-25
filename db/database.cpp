#include "database.h"

namespace DB
{

static const char* s_dbConnection = "QSQLITE";

static QString dnName()
{
	static const char* s_dbName = "ho.sqlite";
	return QCoreApplication::applicationDirPath() + "/" + s_dbName;
}

Database::Database()
	: m_db(QSqlDatabase::addDatabase(s_dbConnection))
{
	Q_ASSERT(QFileInfo(dnName()).exists());

	m_db.setDatabaseName(dnName());

	const bool opened = m_db.open();
	opened;
	Q_ASSERT(opened);
	Q_ASSERT(m_db.isValid());
}

Database::~Database()
{
	m_db.close();
	QSqlDatabase::removeDatabase(s_dbConnection);
}

Energy Database::loadEnergy() const
{
	QSqlQuery query;
	query.exec("SELECT amount, updateTime FROM energy");

	query.next();

	// qt assumes datetime in local format during convert from QVariant, so force to UTC
	QDateTime dt = query.value(1).toDateTime();
	dt.setTimeSpec(Qt::UTC);

	return Energy(query.value(0).toInt(), dt);
}

void Database::saveEnergy(int amount)
{
	Q_ASSERT(amount >= 0);

	QSqlQuery().exec(QString("UPDATE energy SET amount=%1, updateTime=CURRENT_TIMESTAMP").arg(amount));
}

void Database::saveRecord(int locationId, int seconds)
{
	Q_ASSERT(locationId >= 1);
	Q_ASSERT(seconds >= 0);

	QSqlQuery().exec(QString("INSERT INTO records VALUES(NULL,%1,%2)").arg(locationId).arg(seconds));

//	qDebug() << m_db.lastError();
}

bool Database::emptyRecord(int locationId) const
{
	Q_ASSERT(locationId >= 1);

	QSqlQuery query;
	query.exec(QString("SELECT COUNT(*) FROM records WHERE locationId=%1").arg(locationId));

	query.next();

	return query.value(0).toInt() == 0;
}

int Database::bestRecord(int locationId) const
{
	Q_ASSERT(locationId >= 1);

	QSqlQuery query;
	query.exec(QString("SELECT MIN(seconds) FROM records WHERE locationId=%1").arg(locationId));

	query.next();

	return query.value(0).toInt();
}

}