#include "stdafx.h"
#include <memory>
#include "Game.h"
#include "VillainJuicer.h"
#include "Villain.h"
#include "Item.h"
#include "Gru.h"
#include "CGameVisitor.h"
#include "GetScoreVisitor.h"
#include <string>
#include "Minion.h"
#include "MinionJerry.h"
#include "MinionStuart.h"
#include "MinionMutant.h"

using namespace std;
using namespace Gdiplus;

/// Game area width in virtual pixels
const static int Width = 1400;

/// Game area height in virtual pixels
const static int Height = 1100;

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

	wstring time = GetTime();
	DrawTime(graphics, float((Width - 250) / 2.0), -float((Height - 200) / 2.0), time);

	mNewGameButton->Draw(graphics, Width, Height);

	mPlayingArea->DrawArea(graphics, Width, Height);

	
	UpdateScoreMap();
	
	mScoreboard->Draw(graphics, Width, Height);


	

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

void CGame::SpawnRandomMinion()
{
	int spawner = ((double)rand() / RAND_MAX) * 10;
	if (spawner < 4.5) {
		int x = ((double)rand() / RAND_MAX) * 950;
		auto minionJerry = make_shared<CMinionJerry>(this);
		minionJerry->SetLocation((-Width + 550) / 2 + x, (-Height+200) / 2);
		Add(minionJerry);
	}
	else if (spawner < 9) {
		int x = ((double)rand() / RAND_MAX) * 950;
		auto minionStuart = make_shared<CMinionStuart>(this);
		minionStuart->SetLocation((-Width + 550) / 2 + x, (-Height + 200) / 2);
		Add(minionStuart);
	}
	else{
		int x = ((double)rand() / RAND_MAX) * 950;
		auto minionMutant = make_shared<CMinionMutant>(this);
		minionMutant->SetLocation((-Width + 550) / 2 + x, (-Height + 200) / 2);
		Add(minionMutant);
	}
}

/** Accept a visitor for the collection
* \param visitor The visitor for the collection
*/
void CGame::Accept(CGameVisitor *visitor)
{
	for (auto item : mGameTiles)
	{
		item->Accept(visitor);
	}
}

/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CGame::Update(double elapsed)
{
	for (auto i = mGameTiles.rbegin(); i != mGameTiles.rend(); i++)
	{
		if (!(*i)->IsAlive()) {
			mGameOver = true;
			if (mFinalTime == 0) {
				mFinalTime = mTimeInSeconds;
			}
		}
	}
	mTimeInSeconds += elapsed;
	CheckContact();
	if (mTimeInSeconds >= mNextSpawnTime) {
		double nextSpawnInterval = ((double)rand() / RAND_MAX) * .5 + .5;
		mNextSpawnTime = mTimeInSeconds + nextSpawnInterval;
		SpawnRandomMinion();
	}
}

wstring CGame::GetTime() 
{
	int tempTime = !mGameOver ? (int)mTimeInSeconds : (int)mFinalTime;
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
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CGame::HitTestGru(int x, int y)
{
	float virtualX = (x - mXOffset) / mScale;
	float virtualY = (y - mYOffset) / mScale;
	for (auto i = mGameTiles.rbegin(); i != mGameTiles.rend(); i++)
	{
		//to move all pieces, change HitTestGru to HitTest
		if ((*i)->HitTestGru(virtualX, virtualY))
		{
			return *i;
		}
	}

	return  nullptr;
}

/** Test an x,y click location to see if it clicked
* on some item in the PlayingArea.
* \param x X location
* \param y Y location
*/
bool CGame::HitTestNewGame(int x, int y)
{
	float virtualX = (x - mXOffset) / mScale;
	float virtualY = (y - mYOffset) / mScale;
	if (mNewGameButton->HitTest((int)virtualX, (int)virtualY)) {
		mTimeInSeconds = 0;
		mResetStatus = true;
		mNextSpawnTime = 0;
		mGameOver = false;
		mFinalTime = 0;
		return true;
	}
	return false;
}


void CGame::UpdateScoreMap()
{
	CGetScoreVisitor visitor;
	Accept(&visitor);

	mScoreboard->SetScoreMap(visitor.GenerateScoreMap());
	
}

void CGame::CheckContact()
{
	for (auto j = mGameTiles.rbegin(); j != mGameTiles.rend(); j++)
	{
		for (auto i = mGameTiles.rbegin(); i != mGameTiles.rend(); i++)
		{
			if ((*i)->HitTest((*j)->GetX(), (*j)->GetY()) && *i != *j && (*i)->GetLevel() < (*j)->GetLevel())
			{
				(*i)->Kill();
				if ((*i)->IsAlive()) {
					DeleteItem(*i);
				}
				return;
			}
			else if ((*i)->HitTest((*j)->GetX(), (*j)->GetY()) && *i != *j && (*i)->GetLevel() > (*j)->GetLevel())
			{
				(*j)->Kill();
				if ((*j)->IsAlive()) {
					DeleteItem(*j);
				}
				return;
			}
		}
	}
}

/** Kill the item in need of dying
*
* \param item Item who just died
*/
void CGame::DeleteItem(std::shared_ptr<CItem> item)
{
	auto loc = find(begin(mGameTiles), end(mGameTiles), item);
	if (loc != end(mGameTiles))
	{
		mGameTiles.erase(loc);
	}
}