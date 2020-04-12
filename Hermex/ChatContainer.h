#pragma once
#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>

class ChatContainer : public wxControl
{
	wxBoxSizer* boxSizer;
	wxTextCtrl* chatEntry;
	wxRichTextCtrl* chatHistory;
public:
	ChatContainer(wxWindow* parent, wxWindowID id = wxID_ANY);
	~ChatContainer();

	void sendChatMsg(const wxString& message);

	void OnTextEnter(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

