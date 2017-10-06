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
	double wid = mButtonImage->GetWidth();
	double hit = mButtonImage->GetHeight();
	graphics->DrawImage(mButtonImage.get(),
		float((-windowWidth + MarginX) /2.0), float((-windowHeight +  MarginY) /2.0),
		(float)mButtonImage->GetWidth(), (float)mButtonImage->GetHeight());
}
