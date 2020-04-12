#include "ChatContainer.h"
#include "globals.h"

wxBEGIN_EVENT_TABLE(ChatContainer, wxControl)
EVT_TEXT_ENTER(ChatTextBoxId, ChatContainer::OnTextEnter)
wxEND_EVENT_TABLE()

ChatContainer::ChatContainer(wxWindow* parent, wxWindowID id) : wxControl(parent, id)
{
	boxSizer = new wxBoxSizer(wxVERTICAL);
	chatHistory = new wxRichTextCtrl(this);
	chatEntry = new wxTextCtrl(this, ChatTextBoxId, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
	boxSizer->Add(chatHistory, 1, wxEXPAND);
	boxSizer->Add(chatEntry, 0, wxEXPAND);
	this->SetSizer(boxSizer);
	this->Layout();

	chatHistory->SetEditable(false);
}

ChatContainer::~ChatContainer()
{

}

void ChatContainer::OnTextEnter(wxCommandEvent& event)
{
	if(chatEntry->GetValue() == "")
		return;
	sendChatMsg(chatEntry->GetValue());
	chatEntry->SetValue("");
}

void ChatContainer::sendChatMsg(const wxString& message)
{
	chatHistory->AppendText("\nMe: "+message);
	chatHistory->ShowPosition(chatHistory->GetLastPosition());
	// TODO: find url within string, format it as such and attemp to display information about. display image if it points to one.
}