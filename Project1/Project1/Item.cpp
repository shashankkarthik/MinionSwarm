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
* \param aquarium The aquarium this item is a member of
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
