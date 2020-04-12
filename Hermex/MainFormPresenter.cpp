#include "MainFormPresenter.h"

MainFormPresenter::MainFormPresenter()
{
	
}

MainFormPresenter::~MainFormPresenter()
{

}

wxPoint MainFormPresenter::getStartingPosition()
{
	//TODO: use ini file to store and get these values
	return wxPoint(80, 80);
}

wxSize MainFormPresenter::getStartingSize()
{
	//TODO: use ini file to store and get these values
	return wxSize(1280, 720);
}

wxString MainFormPresenter::getTitle()
{
	return wxString("Hermex - chat and screenshare");
}