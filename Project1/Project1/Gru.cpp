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