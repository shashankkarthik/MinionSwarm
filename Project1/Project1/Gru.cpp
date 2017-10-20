/**
 * \file Gru.cpp
 *
 * \author Hector
 * Gru class that manages the gru in the game
 */

#include "stdafx.h"
#include <string>
#include "Gru.h"



using namespace std;
using namespace Gdiplus;

/// image filename 
const wstring GruImageName = L"images/gru.png";

/// Game over text font size
const int GameOverFontSize = 48;

/// X location of start point for game over txt rectangle
const float XLocationGameOver = -150;

/// Game over text box width
const float GameOverWidth = 400;

/// Game over text box height
const float GameOverHeight = 75;

/// Maximum color value
const int MaxColorValue = 255;


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
		Gdiplus::Font myFont(L"Arial", GameOverFontSize);
		RectF layoutRect(XLocationGameOver, 0, GameOverWidth, GameOverHeight);
		StringFormat format;
		format.SetAlignment(StringAlignmentCenter);
		SolidBrush yellowBrush(Color(MaxColorValue, MaxColorValue, MaxColorValue, 0));

		graphics->DrawString(
			string,
			-1,
			&myFont,
			layoutRect,
			&format,
			&yellowBrush);
	}
}

/** Test if Gru is hit
* \param x The x location 
* \param y The y location
* \returns bool The true or false if he's touched
*/
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