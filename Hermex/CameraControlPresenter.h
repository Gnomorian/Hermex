#pragma once
#include <wx/wx.h>
#include "escapi.h"

class CameraControlPresenter
{
	SimpleCapParams cameraProps;
	uint8_t* rgbImageArray;
	wxSize cameraSize;
	wxTimer timer;
public:
	CameraControlPresenter();
	~CameraControlPresenter();
	void nextFrame(wxBitmap*& bitmap, wxSize desiredSize);
	void startCapture(wxWindow* window, int timerId);
	void stopCapture();
};

