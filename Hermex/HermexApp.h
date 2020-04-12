#pragma once

#include <wx/wx.h>
#include "MainForm.h"

class HermexApp : public wxApp
{
	MainForm* mainForm;
public:
	HermexApp();
	~HermexApp();
	bool OnInit();
};

wxIMPLEMENT_APP(HermexApp);