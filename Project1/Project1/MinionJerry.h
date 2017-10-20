/**
 * \file MinionJerry.h
 *
 * \author Hector
 *
 * Jerry is a Minion
 */

#pragma once
#include "Minion.h"
class CMinionJerry :
	public CMinion
{
public:
	CMinionJerry(CGame * game);

	/// Default constructor (disabled)
	CMinionJerry() = delete;

	/// Copy constructor (disabled)
	CMinionJerry(const CMinionJerry &) = delete;

	virtual ~CMinionJerry();

	virtual void Accept(CGameVisitor * visitor) { visitor->VisitMinionJerry(this); }
};

