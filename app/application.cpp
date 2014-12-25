#include "application.h"
#include "db/dbservice.h"
#include "core/energy/energyservice.h"
#include "db/idatabase.h"

namespace App
{
using namespace DB;
using namespace Energy;

Application::Application(int& argc, char* argv[])
	: QApplication(argc, argv)
{
	DBService::init();
	EnergyService::init(DBService::db());

	m_mainFrame.reset(new Gui::MainFrame(DBService::db(), EnergyService::energy()));
	m_mainFrame->showFullScreen();
	m_mainFrame->startMainScreen();
}

Application::~Application()
{
	EnergyService::term(DBService::db());
	DBService::term();
}

}