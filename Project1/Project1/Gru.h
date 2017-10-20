/**
 * \file Gru.h
 *
 * \author Hector
 *
 * Gru is a piece that shouldn't die
 */

#pragma once
#include "Item.h"

/**
* The Gru class that manages Gru in the game
*/
class CGru : public CItem
{

public:

	CGru(CGame * game);

	virtual ~CGru();

	void Draw(Gdiplus::Graphics * graphics);

	/// Default constructor (disabled)
	CGru() = delete;

	/// Copy constructor (disabled)
	CGru(const CGru &) = delete;

	///returns if Gru is alive or not
	bool IsAlive() { return mAlive; }

	void Kill() { mAlive = false; }

	virtual void Accept(CGameVisitor * visitor) { visitor->VisitGru(this); }

	virtual bool HitTestGru(int x, int y);

private:

	/// Gru is alive or not
	bool mAlive = true;

	/// Gru's image 
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;
};

