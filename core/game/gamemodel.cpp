#include "game/gamemodel.h"
#include "core/location/template/xmllocationtemplateloader.h"
#include "core/location/modelgenerator/fixedlocationmodelgenerator.h"
#include "core/location/template/locationtemplate.h"
#include "core/location/timer/timer.h"
#include "db/irecordsstorage.h"
#include "core/location/model/itemsmodel.h"

namespace Game
{
using namespace std;
using namespace DB;
using namespace Location;
using namespace Location::Model;
using namespace Location::Generator;
using namespace Location::Template;
using namespace Location::Template::Persistence;

static auto_ptr<ILocationModel> createModel(const LocationId& id)
{
	XmlLocationTemplateLoader loader(id);
	const auto_ptr<LocationTemplate> tpl = loader.load();

	const FixedLocationModelGenerator gen(*tpl);
	return gen.generate();
}

GameModel::GameModel(const LocationId& id, IRecordsStorage& recordsStorage)
	: m_id(id)
	, m_locationModel(createModel(id))
	, m_timer(new Timer())
	, m_recordsStorage(recordsStorage)
{
	m_timer->start();

	connect(m_locationModel.get(), SIGNAL(itemFound(IItemPtr)), SLOT(onItemFound(IItemPtr)));
}

const LocationId& GameModel::id() const 
{
	return m_id;
}

Location::Model::ILocationModel& GameModel::location() const 
{
	return *m_locationModel;
}

const Location::ITimer& GameModel::timer() const 
{
	return *m_timer;
}

void GameModel::onItemFound(IItemPtr)
{
	if (m_locationModel->activeItems().count() == 0)
	{
		m_timer->stop();
		const bool isNewRecord = saveRecord();
		Q_EMIT win(isNewRecord, m_timer->elapsed());
	}
}

bool GameModel::saveRecord() const
{
	const bool isNewRecord = m_recordsStorage.emptyRecord(id()) ||
							m_timer->elapsed() < m_recordsStorage.bestRecord(id());

	m_recordsStorage.saveRecord(id(), m_timer->elapsed());

	return isNewRecord;
}
}