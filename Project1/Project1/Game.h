#pragma once
#include <memory>
#include <string>
#include <vector>
#include "GameVisitor.h"
#include "NewGame.h"
#include "PlayingArea.h"
#include "Scoreboard.h"
#include "Vector.h"
#include <iterator>
#include <algorithm>

using namespace std;

class CItem;

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
	float mScale = 0;
	float mXOffset = 0;
	float mYOffset = 0;
	double mTimeInSeconds = 0;
	double mFinalTime = 0;
	double mNextSpawnTime = 0;
	bool mResetStatus = false;
	bool mGameOver = false;
	std::unique_ptr<Gdiplus::Bitmap> mJuicerImage;
	std::unique_ptr<Gdiplus::Bitmap> mPokeeballImage;
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


};

