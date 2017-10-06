#pragma once
#include <memory>
#include "GameVisitor.h"
#include "NewGame.h"

class CGame
{
public:

	CGame();

	virtual ~CGame();

	void CGame::OnDraw(Gdiplus::Graphics *graphics, int width, int height);

	void Accept(CGameVisitor * visitor);


private:
	float mScale = 0;
	float mXOffset = 0;
	float mYOffset = 0;
	/// All of the items to populate our aquarium
	std::shared_ptr<CNewGame> mNewGameButton;
	///collection of items

};

