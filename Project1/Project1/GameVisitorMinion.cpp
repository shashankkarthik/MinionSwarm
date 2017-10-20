#include "stdafx.h"
#include "GameVisitorMinion.h"


CGameVisitorMinion::CGameVisitorMinion()
{
}


CGameVisitorMinion::~CGameVisitorMinion()
{
}

/** Visit a CTileBuilding object
* \param building Building we are visiting */
void CGameVisitorMinion::VisitMinionJerry(CMinionJerry *minion)
{
	mNumMinions++;
	mCohesionCenter += minion->GetLocation();
	mMinionTiles.push_back(minion);
}

/** Visit a CTileBuilding object
* \param building Building we are visiting */
void CGameVisitorMinion::VisitMinionStuart(CMinionStuart *minion)
{
	mNumMinions++;
	mCohesionCenter += minion->GetLocation();
	mMinionTiles.push_back(minion);
}

/** Visit a CTileBuilding object
* \param building Building we are visiting */
void CGameVisitorMinion::VisitMinionMutant(CMinionMutant *minion)
{
	mNumMinions++;
	mCohesionCenter += minion->GetLocation();
	mMinionTiles.push_back(minion);
}

