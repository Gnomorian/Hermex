#pragma once
#include <wx/wx.h>
#include "CameraControl.h"

class CameraContainer : public wxControl
{
	CameraControl* camLocal;
	wxGridSizer* cameraGrid;

public:
	CameraContainer(wxWindow* parent, wxWindowID id = wxID_ANY);
	~CameraContainer();

	void OnClose(wxCloseEvent& event);
};

