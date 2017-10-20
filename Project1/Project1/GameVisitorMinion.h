/**
 * \file GameVisitorMinion.h
 *
 * \author Team Hector
 *
 * Minion visitor that calculates and produces the moving of Minions
 */

#pragma once
#include "GameVisitor.h"
#include "Vector.h"
#include "Game.h"
#include "MinionJerry.h"
#include "MinionMutant.h"
#include "MinionStuart.h"

/**
* Minion visitor that manages the Minions movement
*/
class CGameVisitorMinion :
	public CGameVisitor
{
public:
	CGameVisitorMinion();
	~CGameVisitorMinion();

	void VisitMinionJerry(CMinionJerry * minion);
	void VisitMinionMutant(CMinionMutant * minion);
	void VisitMinionStuart(CMinionStuart * minion);

	/** Get the number of buildings
	* \returns CVector of buildings */
	CVector CohesionCenter() { return mCohesionCenter; }

	/**
	* Getter for number of minions
	* \return Number of minions*/
	int NumberMinions() { return mNumMinions; }

	/**
	* Getter for the vector of minions
	* \returns Minion vectos*/
	std::vector<CMinion* > GetMinions() { return mMinionTiles; }

private:
	/// Buildings counter
	CVector mCohesionCenter;
	/// Minion counter
	int mNumMinions = 0;
	/// All of the items to populate our game
	std::vector<CMinion* > mMinionTiles;

};

