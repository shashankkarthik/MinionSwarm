/**
 * \file Gru.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "Gru.h"
#include <string>


using namespace std;
using namespace Gdiplus;

/// image filename 
const wstring GruImageName = L"images/gru.png";

/** Constructor
* \param game The game this is a member of
*/
CGru::CGru(CGame *game) : CItem(game, GruImageName)
{
	mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(GruImageName.c_str()));
	if (mItemImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += GruImageName;
		AfxMessageBox(msg.c_str());
	}
}


/**
* Destructor
*/
CGru::~CGru()
{
}

/**
* Draw this item
* \param graphics Graphics device to draw on
*/
void CGru::Draw(Gdiplus::Graphics *graphics)
{
	if (IsAlive()) {
		double wid = mItemImage->GetWidth();
		double hit = mItemImage->GetHeight();

		graphics->DrawImage(mItemImage.get(),
			float(GetX() + wid / 2), float(GetY() - hit / 2),
			-(float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
	}
	else{
		wstring message = L"Gru is Dead!";
		WCHAR* string = (WCHAR *)message.c_str();
		Gdiplus::Font myFont(L"Arial", 48);
		RectF layoutRect(-150, 0, 400.0f, 75.0f);
		StringFormat format;
		format.SetAlignment(StringAlignmentCenter);
		SolidBrush yellowBrush(Color(255, 255, 255, 0));

		graphics->DrawString(
			string,
			-1,
			&myFont,
			layoutRect,
			&format,
			&yellowBrush);
	}
}

bool CGru::HitTestGru(int x, int y)
{
	double width = mItemImage->GetWidth();
	double height = mItemImage->GetHeight();

	double testX = x - GetX() + width / 2;
	double testY = y - GetY() + height / 2;

	if (testX < 0 || testY < 0 || testX >= width || testY >= height)
	{
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	auto format = mItemImage->GetPixelFormat();
	if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
	{
		// This image has an alpha map, which implements the 
		// transparency. If so, we should check to see if we
		// clicked on a pixel where alpha is not zero, meaning
		// the pixel shows on the screen.
		Color color;
		mItemImage->GetPixel((int)testX, (int)testY, &color);
		return color.GetAlpha() != 0;
	}
	else {
		return true;
	}
}