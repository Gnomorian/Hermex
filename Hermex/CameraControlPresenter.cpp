#include "CameraControlPresenter.h"

CameraControlPresenter::CameraControlPresenter() : cameraProps({ 0 }), rgbImageArray(nullptr), cameraSize(800, 600), isNextFrameRequired(false)
{

}

CameraControlPresenter::~CameraControlPresenter()
{
	delete[] rgbImageArray;
	delete[] cameraProps.mTargetBuf;
}

void CameraControlPresenter::nextFrame(wxBitmap*& pBitmap, wxSize desiredSize)
{
	if (isNextFrameRequired && isCaptureDone(0))
	{
		int rgbArrayPos = 0;
		// convert from bgra to rgb array
		for (int i = 0; i < cameraProps.mWidth * cameraProps.mHeight; i++)
		{
			auto colour = (uint8_t*)&cameraProps.mTargetBuf[i];
			rgbImageArray[rgbArrayPos + 2] = *colour++;
			rgbImageArray[rgbArrayPos + 1] = *colour++;
			rgbImageArray[rgbArrayPos]     = *colour++;
			rgbArrayPos += 3;
		}
		wxImage image(cameraSize.x, cameraSize.y, rgbImageArray, true);

		// wxBitmap has no Create() overload that takes a wxImage, so it has to be recreated every frame.
		delete pBitmap;

		pBitmap = new wxBitmap(image.Scale(desiredSize.x, desiredSize.y), 3);

		doCapture(0);
	}
	else if (pBitmap == nullptr)
	{
		pBitmap = new wxBitmap(cameraSize.x, cameraSize.y);
	}
}

void CameraControlPresenter::startCapture(wxWindow* window, int timerId)
{
	//TODO: select a camera id
	//TODO: fail if camera is not avalable
	if (timer.IsRunning())
		return;
	isNextFrameRequired = true;
	setupESCAPI();
	cameraProps.mHeight = cameraSize.y;
	cameraProps.mWidth = cameraSize.x;
	cameraProps.mTargetBuf = new int[cameraProps.mWidth * cameraProps.mHeight];
	rgbImageArray = new uint8_t[cameraProps.mWidth * cameraProps.mHeight * 3]; // width * height * R G B
	initCapture(0, &cameraProps);
	doCapture(0);
	
	timer.SetOwner(window, timerId);
	//TODO: refreshrate in settings from the camera
	timer.Start(1000 / 30);
}

void CameraControlPresenter::stopCapture()
{
	// stop the timer accessing memory that may not be there anymore
	isNextFrameRequired = false;

	deinitCapture(0);

	wxSleep(1);

	delete[] cameraProps.mTargetBuf;
	cameraProps.mTargetBuf = nullptr;

	delete[] rgbImageArray;
	rgbImageArray = nullptr;
}