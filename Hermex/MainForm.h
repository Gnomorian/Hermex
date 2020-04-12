#pragma once
#include <wx/wx.h>
#include <wx/splitter.h>	

#include "MainFormPresenter.h"
#include "CameraContainer.h"
#include "ChatContainer.h"

class MainForm : public wxFrame
{
	MainFormPresenter* myPresenter;
	wxSplitterWindow* splitChatVideo;
	wxGridSizer* splitterSizer;
	CameraContainer* grpCameraContainer;
	ChatContainer* grpChatContainer;
public:
	MainForm(MainFormPresenter* presenter);
	~MainForm();
};