#pragma once

#include <wx/wx.h>

class MainFormPresenter
{
public:
	MainFormPresenter();
	~MainFormPresenter();
	wxPoint getStartingPosition();
	wxSize getStartingSize();
	wxString getTitle();
};

