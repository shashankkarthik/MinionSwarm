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
