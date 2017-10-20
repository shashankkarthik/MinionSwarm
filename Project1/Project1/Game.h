/**
 * \file Game.h
 *
 * \author Team Hector
 *
 * The class that manages the entire game
 */

#pragma once
#include <memory>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "GameVisitor.h"
#include "NewGame.h"
#include "PlayingArea.h"
#include "Scoreboard.h"
#include "Vector.h"


using namespace std;

class CItem;

/**
* The class that manages the entire game
*/
class CGame
{
public:

	CGame();

	virtual ~CGame();

	virtual void CGame::OnDraw(Gdiplus::Graphics *graphics, int width, int height);

	void Delete();

	void Add(std::shared_ptr<CItem> item);

	void Accept(CGameVisitor * visitor);

	void Update(double elapsed);

	wstring GetTime();

	void SetTime(double time) { mTimeInSeconds = time; };

	std::shared_ptr<CItem> HitTestGru(int x, int y);

	bool HitTestNewGame(int x, int y);

	void UpdateScoreMap();

	void UpdateMinions();

	void UpdateGruLocation();

	void CheckContact();

	void DeleteItem(std::shared_ptr<CItem> item);

	int GetSizemGameTiles() { return mGameTiles.size(); }

	void CGame::DrawTime(Gdiplus::Graphics * graphics, float xLoc, float yLoc, std::wstring score);

	void SpawnRandomMinion();

	const float GetmXOffset() { return mXOffset; }

	const float GetmYOffset() { return mYOffset; }

	const float GetmScale() { return mScale; }
	bool GetResetStatus() { return mResetStatus; }
	void SetResetStatus(bool status) { mResetStatus = status; }

	/// All of the items to populate our game
	std::vector<std::shared_ptr<CItem> > GetMinions();

private:

	/// Virtual pixel scale
	float mScale = 0;

	/// X offset for virtual pixels
	float mXOffset = 0;

	/// Y offset for virtual pixels
	float mYOffset = 0;

	/// Time ofr the clock
	double mTimeInSeconds = 0;

	/// Final time
	double mFinalTime = 0;

	/// Spawn time for the minions
	double mNextSpawnTime = 0;

	/// Reset game flag
	bool mResetStatus = false;

	/// Game over flag
	bool mGameOver = false;

	/// Juicer image for score
	std::unique_ptr<Gdiplus::Bitmap> mJuicerImage;

	/// Pokeeball image for score
	std::unique_ptr<Gdiplus::Bitmap> mPokeeballImage;

	/// Arya image for the score
	std::unique_ptr<Gdiplus::Bitmap> mAryaImage;

	/// All of the items to populate our game
	std::shared_ptr<CNewGame> mNewGameButton;
	/// All of the items to populate our game
	std::vector<std::shared_ptr<CItem> > mGameTiles;
	/// The object for the PlayingArea
	std::shared_ptr<CPlayingArea> mPlayingArea;
	///Scoreboard
	std::shared_ptr<CScoreboard> mScoreboard;

	///Vector of the center of all the objects
	CVector cohesionCenter;

	///Vector containing Gru's X and Y coordinates
	CVector mGruLocation;


};

