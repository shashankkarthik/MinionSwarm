#include "stdafx.h"
#include <memory>
#include "Game.h"
#include "VillainJuicer.h"
#include "Villain.h"
#include "Item.h"
#include "Gru.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Game area width in virtual pixels
const static int Width = 1400;

/// Game area height in virtual pixels
const static int Height = 1100;

/*
const wstring JuicerImageName = L"images/juicer.png";
const wstring PokeeballImageName = L"images/pokeball.png";
const wstring AryaImageName = L"images/arya.png";*/

CGame::CGame()
{
	shared_ptr<CNewGame> newGame(new CNewGame());
	mNewGameButton = newGame;

	shared_ptr<CPlayingArea> playingArea(new CPlayingArea());
	mPlayingArea = playingArea;

	shared_ptr<CScoreboard> scoreBoard(new CScoreboard());
	mScoreboard = scoreBoard;


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

	mScoreboard->Draw(graphics, Width, Height);

/*
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

	wstring time = GetTime();

	DrawTime(graphics, float((Width - 250) / 2.0), -float((Height - 200) / 2.0), time);

	graphics->DrawImage(mJuicerImage.get(), float((Width - 240) / 2.0) , -float((Height - 300) / 2.0));
	DrawScore(graphics, float((Width - 200) / 2.0) , -float((Height - 600) / 2.0), L"0");


	graphics->DrawImage(mPokeeballImage.get(), float((Width - 200) / 2.0), -float((Height - 700) / 2.0));
	DrawScore(graphics, float((Width - 200) / 2.0), -float((Height - 800) / 2.0), L"0");

	graphics->DrawImage(mAryaImage.get(), float((Width - 275) / 2.0), -float((Height - 900) / 2.0));
	DrawScore(graphics, float((Width - 200) / 2.0), -float((Height - 1200) / 2.0), L"0");*/

	///after gru is added then I can test this - Moritz
	for (auto item : mGameTiles)
	{
		item->Draw(graphics);
	}

}

void CGame::Delete()
{
	mGameTiles.clear();
}

/*
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
}*/

/**
* Add an item to the game
* \param item New item to add
*/
void CGame::Add(std::shared_ptr<CItem> item)
{
	mGameTiles.push_back(item);
}

void CGame::DrawTime(Gdiplus::Graphics * graphics, float xLoc, float yLoc, wstring time)
{
	time = time + L"\0";
	WCHAR* string = (WCHAR *)time.c_str();
	Gdiplus::Font myFont(L"Arial", 20);
	RectF layoutRect(xLoc, yLoc, 80.0f, 50.0f);
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

/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CGame::Update(double elapsed)
{
	mTimeInSeconds += elapsed;
}

wstring CGame::GetTime() {
	int tempTime = (int)mTimeInSeconds;
	string minutes = to_string(tempTime / 60);
	string seconds = to_string(tempTime % 60);
	if (seconds.length() == 1) {
		seconds = "0" + seconds;
	}
	string stringConvertedTime = minutes + ":" + seconds;
	std::wstring convertedTime(stringConvertedTime.length(), L' '); // Make room for characters

										   // Copy string to wstring.
	std::copy(stringConvertedTime.begin(), stringConvertedTime.end(), convertedTime.begin());
	return convertedTime;
}

/** Test an x,y click location to see if it clicked
* on some item in the PlayingArea.
* \param x X location
* \param y Y location
*/
void CGame::HitTest(int x, int y)
{
	float virtualX = (x - mXOffset) / mScale;
	float virtualY = (y - mYOffset) / mScale;
	if (mNewGameButton->HitTest((int)virtualX, (int)virtualY)) {
		mTimeInSeconds = 0;
	}
}