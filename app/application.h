#pragma once
#include "mainframe.h"

namespace App
{

class Application : public QApplication
{
public:
	Application(int& argc, char* argv[]);
	~Application();

private:
	std::auto_ptr<Gui::MainFrame> m_mainFrame;
};

}