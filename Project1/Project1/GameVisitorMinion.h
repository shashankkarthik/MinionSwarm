#pragma once
#include "GameVisitor.h"
#include "Vector.h"
#include "Game.h"
#include "MinionJerry.h"
#include "MinionMutant.h"
#include "MinionStuart.h"

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

	int NumberMinions() { return mNumMinions; }

	std::vector<CMinion* > GetMinions() { return mMinionTiles; }

private:
	/// Buildings counter
	CVector mCohesionCenter;
	/// Minion counter
	int mNumMinions = 0;
	/// All of the items to populate our game
	std::vector<CMinion* > mMinionTiles;

};

