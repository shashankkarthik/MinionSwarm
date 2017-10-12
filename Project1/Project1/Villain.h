/**
 * \file Villain.h
 *
 * \author Hector
 *
 * Villain 
 */

#pragma once
#include "Item.h"

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

private:
	///Killing points for the villain
	int mPoints = 0;

	///Point multiplier for the killer
	int mPointMult = 0;
};

