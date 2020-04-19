#include "CameraContainer.h"

CameraContainer::CameraContainer(wxWindow* parent, wxWindowID id) : wxControl(parent, id)
{
	this->SetBackgroundColour(wxColor(0, 0, 0));

	camLocal = new CameraControl(this, wxID_ANY);

	// as more cameras are added we add more rows/colums to they evenly spread out
	cameraGrid = new wxGridSizer(1, 1, 10, 10);
	// shaped makes it keep its aspect ratio
	cameraGrid->Add(camLocal, 0, wxSHAPED | wxALIGN_CENTRE);
	this->SetSizer(cameraGrid);
	this->Layout();
}

CameraContainer::~CameraContainer()
{

}

void CameraContainer::OnClose(wxCloseEvent& event)
{
	// tell the camera to stop so its timers and background processes dont crash
	camLocal->OnClose(event);
}