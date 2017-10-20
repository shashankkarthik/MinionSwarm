/**
 * \file NewGame.h
 *
 * \author Team Hector
 *
 * New Game class that represents the button
 */

#pragma once
#include <memory>
#include "GameVisitor.h"

/**
* New Game Button class
*/
class CNewGame
{
public:
	CNewGame();
	virtual ~CNewGame();
	void Draw(Gdiplus::Graphics * graphics, int windowWidth, int windowHeight);

	bool HitTest(int x, int y);

private:

	/// Image for the button
	std::unique_ptr<Gdiplus::Bitmap> mButtonImage;

	/// New Game button x location
	float mX = 0;

	/// New Game button y location
	float mY = 0;
};

