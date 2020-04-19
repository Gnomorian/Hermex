#include "MainFormMenu.h"
#include "escapi.h"

MainFormMenu::MainFormMenu()
{
	collateAllSources();
	if (sources.size() != 0)
	{
		wxMenu* mnuSelectSource = new wxMenu(sources[0].name);
		this->Append(mnuSelectSource, "&Sources");
		for (int i = 1; i < sources.size(); i++)
		{
			mnuSelectSource->Append(new wxMenuItem(mnuSelectSource, -2, sources[i].name));
		}
	}
}

MainFormMenu::~MainFormMenu()
{

}

void MainFormMenu::collateAllSources()
{
	for (int i = 0; i < countCaptureDevices(); i++)
	{
		wxString deviceName;
		if (getCameraSourceDetails(i, deviceName))
		{
			sources.push_back({i, deviceName});
		}
	}
	sources.push_back({999, "DummyDevice"});
}

bool MainFormMenu::getCameraSourceDetails(int id, wxString& name)
{
	if (id >= countCaptureDevices())
		return false;

	name.clear();

	char nameBuffer[256];
	getCaptureDeviceName(id, nameBuffer, 256);

	name.assign(nameBuffer, strlen(nameBuffer));
	return true;
}