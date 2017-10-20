/**
 * \file MinionJerry.h
 *
 * \author Hector
 *
 * Jerry is a Minion
 */

#pragma once
#include "Minion.h"

/**
* Class for the Minion Jerry
*/
class CMinionJerry :
	public CMinion
{
public:
	CMinionJerry(CGame * game);

	CMinionJerry() = delete;

	CMinionJerry(const CMinionJerry &) = delete;

	virtual ~CMinionJerry();

	virtual void Accept(CGameVisitor * visitor) { visitor->VisitMinionJerry(this); }
};

