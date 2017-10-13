/**
 * \file Gru.h
 *
 * \author Hector
 *
 * Gru is a piece that shouldn't die
 */

#pragma once
#include "Item.h"
class CGru : public CItem
{

public:

	CGru(CGame * game);

	virtual ~CGru();

	/// Default constructor (disabled)
	CGru() = delete;

	/// Copy constructor (disabled)
	CGru(const CGru &) = delete;

	///returns if Gru is alive or not
	bool IsAlive() { return mAlive; }

	virtual void Accept(CGameVisitor * visitor) { }

private:

	///Gru is alive or not
	bool mAlive = true;
};

