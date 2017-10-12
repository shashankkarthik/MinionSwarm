#include "stdafx.h"
#include <string>
#include "NewGame.h"

using namespace std;
using namespace Gdiplus;

/// Button filename 
const wstring NewGameImageName = L"images/new-game.png";

/// Margin from left 
const int MarginX = 25;

/// Margin from top
const int MarginY = 100;

CNewGame::CNewGame()
{
	mButtonImage = unique_ptr<Bitmap>(Bitmap::FromFile(NewGameImageName.c_str()));
	if (mButtonImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += NewGameImageName;
		AfxMessageBox(msg.c_str());
	}
}


CNewGame::~CNewGame()
{
}

/**
* Draw the new game button
* \param graphics Graphics device to draw on
*/
void CNewGame::Draw(Gdiplus::Graphics *graphics, int windowWidth, int windowHeight)
{
	mX = (-windowWidth + MarginX) / 2.0;
	mY = (-windowHeight + MarginY) / 2.0;
	graphics->DrawImage(mButtonImage.get(),
		mX, mY,
		(float)mButtonImage->GetWidth(), (float)mButtonImage->GetHeight());
}

/**
* Test to see if we hit this object with a mouse.
* \param x X position to test
* \param y Y position to test
* \return true if hit.
*/
bool CNewGame::HitTest(int x, int y)
{
	double wid = mButtonImage->GetWidth();
	double hit = mButtonImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to theimage top corner
	double testX = x - mX + wid/2;
	double testY = y - mY + hit/2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	auto format = mButtonImage->GetPixelFormat();
	if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
	{
		// This image has an alpha map, which implements the 
		// transparency. If so, we should check to see if we
		// clicked on a pixel where alpha is not zero, meaning
		// the pixel shows on the screen.
		Color color;
		mButtonImage->GetPixel((int)testX, (int)testY, &color);
		return color.GetAlpha() != 0;
	}
	else {
		return true;
	}
}