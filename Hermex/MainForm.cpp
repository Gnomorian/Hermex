#include "MainForm.h"
#include <wx/dcbuffer.h>

MainForm::MainForm(MainFormPresenter* presenter) : wxFrame(nullptr, wxID_ANY, wxEmptyString)
{
	myPresenter = presenter;
	this->SetPosition(presenter->getStartingPosition());
	this->SetTitle(presenter->getTitle());
	this->SetSize(presenter->getStartingSize());

	splitChatVideo = new wxSplitterWindow(this, wxID_ANY);
	splitterSizer = new wxGridSizer(1, 1, 0, 0);
	splitterSizer->Add(splitChatVideo, 1, wxEXPAND | wxALIGN_LEFT | wxALIGN_TOP);
	this->SetSizer(splitterSizer);
	this->Layout();

	grpCameraContainer = new CameraContainer(splitChatVideo);
	grpChatContainer = new ChatContainer(splitChatVideo);

	splitChatVideo->SplitHorizontally(grpCameraContainer, grpChatContainer);
}

MainForm::~MainForm()
{
	delete myPresenter;
}