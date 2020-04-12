#include "CameraControl.h"
#include "globals.h"
#include <wx/dcbuffer.h>

wxBEGIN_EVENT_TABLE(CameraControl, wxControl)
EVT_PAINT(CameraControl::OnPaint)
EVT_TIMER(CameraControlTimerId, CameraControl::OnTimer)
EVT_CLOSE(CameraControl::OnClose)
wxEND_EVENT_TABLE()

CameraControl::CameraControl(wxWindow* parent, wxWindowID id) : wxControl(parent, id), bitmap(nullptr)
{
	// the container should expand the camera maintaining its aspect radio, default is 6/9
	this->SetSize(wxSize(9, 6));

	// allow  double buffering to prevent flickering
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);

	myPresenter = new CameraControlPresenter();
	myPresenter->startCapture(this, CameraControlTimerId);
}

CameraControl::~CameraControl()
{
	delete myPresenter;
}

void CameraControl::OnPaint(wxPaintEvent& event)
{
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();
	myPresenter->nextFrame(bitmap, this->GetSize());
	dc.DrawBitmap(*bitmap, wxPoint(0, 0));
}

void CameraControl::OnTimer(wxTimerEvent& event)
{
	this->Refresh(false);
}

void CameraControl::OnClose(wxCloseEvent& event)
{
	myPresenter->stopCapture();
}