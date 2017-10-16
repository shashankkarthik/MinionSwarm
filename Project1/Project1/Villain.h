/**
 * \file Villain.h
 *
 * \author Hector
 *
 * Villain 
 */

#pragma once
#include "Item.h"

using namespace Gdiplus;
using namespace std;

 /**
 * Base class for a Villain
 * This applies to all of the Villains in the game
 */
class CVillain : public CItem
{
protected:
	CVillain(CGame * game, const std::wstring & filename, int const pointMult);

public:
	/// Default constructor (disabled)
	CVillain() = delete;

	/// Copy constructor (disabled)
	CVillain(const CVillain &) = delete;	
	
	virtual ~CVillain();

	void AddPoints(int points) { mPoints += points * mPointMult; }

	int GetScore() { return mPoints; }

	void SetScore(int newScore) { mPoints = newScore; } //For use with new game? Idk i just thought I would leave this here -Shashank

private:
	///Killing points for the villain
	int mPoints = 0;

	///Point multiplier for the killer
	int mPointMult = 0;

	int mLevel = 2;
};

