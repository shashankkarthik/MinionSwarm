#include "stdafx.h"
#include <memory>
#include "Game.h"
#include "VillainJuicer.h"
#include "Villain.h"
#include "Item.h"
#include "Gru.h"
#include "CGameVisitor.h"
#include "GetScoreVisitor.h"
#include "GameVisitorMinion.h"
#include "GruLocationVisitor.h"
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

/// Timer X location
const int TimerXLocation = 250;

/// Timer Y location
const int TimerYLocation = 200;

/// X Padding for timer's rectangle
const float TimerXPadding = 80.0;

/// Y Padding for timer's rectangle
const float TimerYPadding = 50.0;

/// Maximum color value
const int MaxColorValue = 255;

/// Maximum Minion type spawn chances
const int SpawnChances = 10;

/// Maximum Minion Spawn Area
const int MaxMinionSpawnArea = 950;

/// Jerry spawn chances
const float JerrySpawnChances = 4.5;

/// Stuart spawn chances
const float StuartSpawnChances = 9;

/// Minimum X location for minion spawning
const int MinXLocationMinionSpawn = 550;

/// Minimum Y location for minion spawning
const int MinYLocationMinionSpawn = 200;

/// Font size for timer
const int TimerFontSize = 20;

/// Range of spawn interval
const float SpawnTimeRange = .5;

/// Range of spawn interval
const float SpawnTimeMin = .5;

/// Time converter
const int TimeConverter = 60;

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
	DrawTime(graphics, float((Width - TimerXLocation) / 2.0), -float((Height - TimerYLocation) / 2.0), time);

	mNewGameButton->Draw(graphics, Width, Height);

	mPlayingArea->DrawArea(graphics, Width, Height);

	
	UpdateScoreMap();
	
	mScoreboard->Draw(graphics, Width, Height);


	

	///after gru is added then I can test this - Moritz
	for (auto item : mGameTiles)
	{
		item->Draw(graphics);
		item->SetBorders((float)Width, (float)Height);
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
	Gdiplus::Font myFont(L"Arial", TimerFontSize);
	RectF layoutRect(xLoc, yLoc, TimerXPadding, TimerYPadding);
	StringFormat format;
	format.SetAlignment(StringAlignmentCenter);
	SolidBrush greenBrush(Color(MaxColorValue, 0, MaxColorValue, 0));

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
	int spawner = (int)(((double)rand() / RAND_MAX) * SpawnChances);
	if (spawner < JerrySpawnChances) {
		int x = (int)(((double)rand() / RAND_MAX) * MaxMinionSpawnArea);
		auto minionJerry = make_shared<CMinionJerry>(this);
		minionJerry->SetLocation((-Width + MinXLocationMinionSpawn) / 2 + x, (-Height+MinYLocationMinionSpawn) / 2);
		Add(minionJerry);
	}
	else if (spawner < StuartSpawnChances) {
		int x = (int)(((double)rand() / RAND_MAX) * MaxMinionSpawnArea);
		auto minionStuart = make_shared<CMinionStuart>(this);
		minionStuart->SetLocation((-Width + MinXLocationMinionSpawn) / 2 + x, (-Height + MinYLocationMinionSpawn) / 2);
		Add(minionStuart);
	}
	else{
		int x = (int)(((double)rand() / RAND_MAX) * MaxMinionSpawnArea);
		auto minionMutant = make_shared<CMinionMutant>(this);
		minionMutant->SetLocation((-Width + MinXLocationMinionSpawn) / 2 + x, (-Height + MinYLocationMinionSpawn) / 2);
		Add(minionMutant);
	}
}

std::vector<std::shared_ptr<CItem>> CGame::GetMinions()
{
	/// All of the items to populate our game
	std::vector<std::shared_ptr<CItem> > mMinionTiles;

	if (mGameOver)
	{
		//vector<std::shared_ptr<CItem> > new_(mGameTiles.begin()+2, mGameTiles.end());
		copy(mGameTiles.begin() + 3, mGameTiles.end(), back_inserter(mMinionTiles));
	}
	else
	{
		copy(mGameTiles.begin() + 4, mGameTiles.end(), back_inserter(mMinionTiles));

	}

	return mMinionTiles;
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
	//make minions move
	

	for (auto i = mGameTiles.rbegin(); i != mGameTiles.rend(); i++)
	{
		(*i)->Move(elapsed);
		
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
		double nextSpawnInterval = ((double)rand() / RAND_MAX) * SpawnTimeRange + SpawnTimeMin;
		mNextSpawnTime = mTimeInSeconds + nextSpawnInterval;
		SpawnRandomMinion();
	}
}

wstring CGame::GetTime() 
{
	int tempTime = !mGameOver ? (int)mTimeInSeconds : (int)mFinalTime;
	string minutes = to_string(tempTime / TimeConverter);
	string seconds = to_string(tempTime % TimeConverter);
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
		if ((*i)->HitTestGru((int)virtualX, (int)virtualY))
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

void CGame::UpdateMinions()
{
	CGameVisitorMinion visitor;
	Accept(&visitor);

	auto numberMinions = visitor.NumberMinions();
	auto totalXY = visitor.CohesionCenter();
	std::vector<CMinion *> minionVector = visitor.GetMinions();
	CVector cohesionCenter = totalXY / numberMinions;

	if (mGameOver)
	{
		mGruLocation.Set(0, 0);
	}

	for (auto i = mGameTiles.rbegin(); i != mGameTiles.rend(); i++)
	{
		auto alignemnt = (*i)->Alignment(minionVector);
		auto separation = (*i)->Separation(minionVector);
		(*i)->Flock(cohesionCenter, numberMinions, alignemnt, mGruLocation, mGameOver, separation);
	}
}

void CGame::UpdateGruLocation()
{
	CGruLocationVisitor visitor;
	Accept(&visitor);

	double x = visitor.GetGruLocation().X();
	double y = visitor.GetGruLocation().Y();

	mGruLocation.Set(x, y);
}


void CGame::CheckContact()
{
	UpdateMinions();
	UpdateGruLocation();
	if (!mGameOver)
	{
		for (auto j = mGameTiles.rbegin(); j != mGameTiles.rend(); j++)
		{
			for (auto i = mGameTiles.rbegin(); i != mGameTiles.rend(); i++)
			{
				if ((*i)->HitTest((int)((*j)->GetX()), int((*j)->GetY())) && *i != *j && (*i)->GetLevel() < (*j)->GetLevel())
				{
					(*i)->Kill();
					if ((*i)->IsAlive()) {
						(*j)->AddPoints((*i)->GetPoints());
						DeleteItem(*i);
						UpdateScoreMap();
					}
					return;
				}
				else if ((*i)->HitTest((int)((*j)->GetX()), (int)((*j)->GetY())) && *i != *j && (*i)->GetLevel() > (*j)->GetLevel())
				{
					(*j)->Kill();
					if ((*j)->IsAlive()) {
						(*i)->AddPoints((*j)->GetPoints());
						DeleteItem(*j);
						UpdateScoreMap();
					}
					return;
				}
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

