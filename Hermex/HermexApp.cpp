#include "HermexApp.h"

HermexApp::HermexApp() : mainForm(nullptr)
{

}

HermexApp::~HermexApp()
{

}

bool HermexApp::OnInit()
{
	auto presenter = new MainFormPresenter;
	mainForm = new MainForm(presenter);
	mainForm->Show();
	return true;
}