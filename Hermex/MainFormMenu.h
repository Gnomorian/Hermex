#pragma once
#include <wx/wx.h>
#include <vector>

struct CameraSource
{
	int id;
	wxString name;
};

class MainFormMenu : public wxMenuBar
{
	std::vector<CameraSource> sources;
public:
	MainFormMenu();
	~MainFormMenu();

	void collateAllSources();
	bool getCameraSourceDetails(int id, wxString& name);
};

