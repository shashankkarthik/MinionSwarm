/**
 * \file Item.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "Item.h"
#include "Game.h"

using namespace Gdiplus;
using namespace std;

/** Constructor
* \param game The game this item is a member of
*/
CItem::CItem(CGame *game, const std::wstring &filename) : mGameTiles(game)
{
	mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mItemImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}


/**
* Destructor
*/
CItem::~CItem()
{
}

/**
* Draw our item
* \param graphics The graphics context to draw on
*/
void CItem::Draw(Gdiplus::Graphics *graphics)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	graphics->DrawImage(mItemImage.get(),
		float(GetX() + wid / 2), float(GetY() - hit / 2),
		-(float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
	
}

bool CItem::HitTest(int x, int y)
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

void CItem::SetBorders(float x, float y) {
	mXLeftBorder = float((-x + 500) / 2.0);
	mYTopBorder = float((-y + 100) / 2.0);
	mXRightBorder = mXLeftBorder + 1000;
	mYBottomBorder = mYTopBorder + 1000;
}

void CItem::SetLocation(double x, double y)
{
	if (mXLeftBorder != 0 && mYTopBorder != 0) {
		double wid = mItemImage->GetWidth();
		double hit = mItemImage->GetHeight();
		if (x - wid/2 < mXLeftBorder || x + wid/2 > mXRightBorder) {
			x = GetX();
		}

		if (y - hit/2 < mYTopBorder || y + hit/2 > mYBottomBorder) {
			y = GetY();
		}
	}

	location.Set(x, y);
}