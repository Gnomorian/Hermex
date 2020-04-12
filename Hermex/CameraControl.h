#pragma once
#include <wx/wx.h>
#include "CameraControlPresenter.h"
#include "globals.h"

class CameraControl : public wxControl
{
	CameraControlPresenter* myPresenter;
	wxBitmap* bitmap;
public:
	CameraControl(wxWindow* parent, wxWindowID id = wxID_ANY);
	~CameraControl();
	
	void OnPaint(wxPaintEvent& event);
	void OnTimer(wxTimerEvent& event);
	void OnClose(wxCloseEvent& event);
	wxDECLARE_EVENT_TABLE();
};

