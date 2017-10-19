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
void CGameVisitorMinion::VisitMinion(CMinion *Minion)
{
	mNumMinions++;
	mCohesionCenter += Minion->GetLocation();
	mMinionTiles.push_back(Minion);
}
