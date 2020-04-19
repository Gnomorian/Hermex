#pragma once
#include <wx/wx.h>
#include <wx/splitter.h>

#include "MainFormPresenter.h"
#include "CameraContainer.h"
#include "ChatContainer.h"
#include "MainFormMenu.h"

class MainForm : public wxFrame
{
	MainFormPresenter* myPresenter;
	wxSplitterWindow* splitChatVideo;
	wxGridSizer* splitterSizer;
	CameraContainer* grpCameraContainer;
	ChatContainer* grpChatContainer;
	MainFormMenu* menu;
public:
	MainForm(MainFormPresenter* presenter);
	~MainForm();
	
	void OnClose(wxCloseEvent& event);
	wxDECLARE_EVENT_TABLE();
};