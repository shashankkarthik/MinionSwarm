#include "stdafx.h"
#include <memory>
#include "Game.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Game area width in virtual pixels
const static int Width = 1400;

/// Game area height in virtual pixels
const static int Height = 1100;


const wstring JuicerImageName = L"images/juicer.png";
const wstring PokeeballImageName = L"images/pokeball.png";
const wstring AryaImageName = L"images/arya.png";

CGame::CGame()
{
	shared_ptr<CNewGame> newGame(new CNewGame());
	mNewGameButton = newGame;

	shared_ptr<CPlayingArea> playingArea(new CPlayingArea());
	mPlayingArea = playingArea;
}


CGame::~CGame()
{
}

/**
* Draw the game area
* \param graphics The GDI+ graphics context to draw on
* \param width Width of the client window
* \param height Height of the client window
*/
void CGame::OnDraw(Gdiplus::Graphics *graphics, int width, int height)
{
	// Fill the background with black
	SolidBrush brush(Color::Black);
	graphics->FillRectangle(&brush, 0, 0, width, height);

	//
	// Automatic Scaling
	//
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	mScale = min(scaleX, scaleY);

	mXOffset = width / 2.0f;
	mYOffset = height / 2.0f;

	graphics->TranslateTransform(mXOffset, mYOffset);
	graphics->ScaleTransform(mScale, mScale);

	// From here on you are drawing virtual pixels

	mNewGameButton->Draw(graphics, Width, Height);

	mPlayingArea->DrawArea(graphics, Width, Height);


	mJuicerImage = unique_ptr<Bitmap>(Bitmap::FromFile(JuicerImageName.c_str()));
	if (mJuicerImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += JuicerImageName;
		AfxMessageBox(msg.c_str());
	}

	mPokeeballImage = unique_ptr<Bitmap>(Bitmap::FromFile(PokeeballImageName.c_str()));
	if (mPokeeballImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += PokeeballImageName;
		AfxMessageBox(msg.c_str());
	}

	mAryaImage = unique_ptr<Bitmap>(Bitmap::FromFile(AryaImageName.c_str()));
	if (mAryaImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += AryaImageName;
		AfxMessageBox(msg.c_str());
	}

	DrawTime(graphics, L"0:00");

	graphics->DrawImage(mJuicerImage.get(), 650, -400);
	DrawScore(graphics, 666.0f, -250.0f, L"0");

	graphics->DrawImage(mPokeeballImage.get(), 666, -200);
	DrawScore(graphics, 666.0f, -145, L"0");

	graphics->DrawImage(mAryaImage.get(), 625, -95);
	DrawScore(graphics, 666.0f, 60, L"0");


}



void CGame::DrawScore(Gdiplus::Graphics * graphics, float xLoc, float yLoc, wstring score)
{
	score = score + L"\0";
	WCHAR* string = (WCHAR *)score.c_str();
	Gdiplus::Font myFont(L"Arial", 16);
	RectF layoutRect(xLoc, yLoc, 50.0f, 50.0f);
	StringFormat format;
	format.SetAlignment(StringAlignmentCenter);
	SolidBrush greenBrush(Color(255, 0, 255, 0));

	graphics->DrawString(
		string,
		-1,
		&myFont,
		layoutRect,
		&format,
		&greenBrush);
}

void CGame::DrawTime(Gdiplus::Graphics * graphics, wstring time)
{
	time = time + L"\0";
	WCHAR* string = (WCHAR *)time.c_str();
	Gdiplus::Font myFont(L"Arial", 20);
	RectF layoutRect(650.0f, -450.0f, 80.0f, 50.0f);
	StringFormat format;
	format.SetAlignment(StringAlignmentCenter);
	SolidBrush greenBrush(Color(255, 0, 255, 0));

	graphics->DrawString(
		string,
		-1,
		&myFont,
		layoutRect,
		&format,
		&greenBrush);

}

/** Accept a visitor for the collection
* \param visitor The visitor for the collection
*/
void CGame::Accept(CGameVisitor *visitor)
{

}