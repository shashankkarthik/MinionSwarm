#pragma once
#include <memory>
#include <string>
#include <vector>
#include "GameVisitor.h"
#include "NewGame.h"
#include "PlayingArea.h"

class CItem;

class CGame
{
public:

	CGame();

	virtual ~CGame();

	virtual void CGame::OnDraw(Gdiplus::Graphics *graphics, int width, int height);

	void Accept(CGameVisitor * visitor);

	void CGame::DrawScore(Gdiplus::Graphics * graphics, float xLoc, float yLoc, std::wstring score);

	void CGame::DrawTime(Gdiplus::Graphics * graphics, float xLoc, float yLoc, std::wstring score);


private:
	float mScale = 0;
	float mXOffset = 0;
	float mYOffset = 0;

	std::unique_ptr<Gdiplus::Bitmap> mJuicerImage;
	std::unique_ptr<Gdiplus::Bitmap> mPokeeballImage;
	std::unique_ptr<Gdiplus::Bitmap> mAryaImage;

	/// All of the items to populate our aquarium
	std::shared_ptr<CNewGame> mNewGameButton;
	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mGameTiles;
	/// The object for the PlayingArea
	std::shared_ptr<CPlayingArea> mPlayingArea;

};

