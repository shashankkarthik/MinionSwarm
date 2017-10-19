#pragma once
#include "GameVisitor.h"
#include "Vector.h"
#include "Game.h"
#include "Minion.h"
class CGameVisitorMinion :
	public CGameVisitor
{
public:
	CGameVisitorMinion();
	~CGameVisitorMinion();

	void VisitMinion(CMinion * Minion);

	/** Get the number of buildings
	* \returns CVector of buildings */
	CVector CohesionCenter() { return mCohesionCenter; }

	int NumberMinions() { return mNumMinions; }

private:
	/// Buildings counter
	CVector mCohesionCenter;
	/// Minion counter
	int mNumMinions = 0;
	/// All of the items to populate our game
	std::vector<CMinion* > mMinionTiles;

};

