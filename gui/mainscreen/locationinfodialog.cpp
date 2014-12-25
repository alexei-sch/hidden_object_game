#include "locationinfodialog.h"
#include "db/irecordsstorage.h"
#include "gui/common/timeformatter.h"

namespace Gui
{
using namespace DB;
using namespace Location;

static QString record(const LocationId& id, const IRecordsStorage& recordsStorage)
{
	QString str("best time of the room: <b>%1</b>");
	if (recordsStorage.emptyRecord(id))
	{
		return str.arg("n/a");
	}
	else
	{
		return str.arg(TimeFormatter::format(recordsStorage.bestRecord(id)));
	}
}

LocationInfoDialog::LocationInfoDialog(const Location::LocationId& id, const IRecordsStorage& recordsStorage)
	: Dialog(record(id, recordsStorage), "start now!", "never mind...")
	, m_id(id)
{
	connect(this, SIGNAL(accepted()), SLOT(onAccepted()));
}

void LocationInfoDialog::onAccepted()
{
	Q_EMIT showLocation(m_id);
}

}