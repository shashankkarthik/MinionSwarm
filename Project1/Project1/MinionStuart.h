/**
 * \file MinionStuart.h
 *
 * \author Hector
 *
 * Stewart is a Minion
 */

#pragma once
#include "Minion.h"

/**
* Class that describes the Stuart Minion
*/
class CMinionStuart :
	public CMinion
{
public:
	CMinionStuart(CGame * game);

	CMinionStuart() = delete;

	CMinionStuart(const CMinionStuart &) = delete;

	virtual ~CMinionStuart();

	virtual void Accept(CGameVisitor * visitor) { visitor->VisitMinionStuart(this); }
};

