#pragma once
#include "gui/dialogs/dialog.h"
#include "core/location/locationid.h"

namespace DB
{
class IRecordsStorage;
}

namespace Gui
{
using Location::LocationId;

class LocationInfoDialog : public Dialogs::Dialog
{
	Q_OBJECT

public:
	LocationInfoDialog(const Location::LocationId& id, const DB::IRecordsStorage& recordsStorage);

public:
	Q_SIGNAL void showLocation(const LocationId& id);

private:
	Q_SLOT void onAccepted();

private:
	const Location::LocationId m_id;
};

}