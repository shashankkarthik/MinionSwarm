/**
 * \file GameVisitorMinion.cpp
 *
 * \author Team Hector
 * Concrete visitor that updates the minions to move/destoryed
 */

#include "stdafx.h"
#include "GameVisitorMinion.h"

/**
* Constructor
*/
CGameVisitorMinion::CGameVisitorMinion()
{
}

/**
* Constructor
*/
CGameVisitorMinion::~CGameVisitorMinion()
{
}

/** Visit a CItem object
* \param minion Minion we are visiting */
void CGameVisitorMinion::VisitMinionJerry(CMinionJerry *minion)
{
	mNumMinions++;
	mCohesionCenter += minion->GetLocation();
	mMinionTiles.push_back(minion);
}

/** Visit a CItem object
* \param minion Minion we are visiting */
void CGameVisitorMinion::VisitMinionStuart(CMinionStuart *minion)
{
	mNumMinions++;
	mCohesionCenter += minion->GetLocation();
	mMinionTiles.push_back(minion);
}

/** Visit a CItem object
* \param minion Minion we are visiting */
void CGameVisitorMinion::VisitMinionMutant(CMinionMutant *minion)
{
	mNumMinions++;
	mCohesionCenter += minion->GetLocation();
	mMinionTiles.push_back(minion);
}

