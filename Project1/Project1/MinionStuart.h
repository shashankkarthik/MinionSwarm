/**
 * \file MinionStuart.h
 *
 * \author Hector
 *
 * Stewart is a Minion
 */

#pragma once
#include "Minion.h"
class CMinionStuart :
	public CMinion
{
public:
	CMinionStuart(CGame * game);

		/// Default constructor (disabled)
	CMinionStuart() = delete;

		/// Copy constructor (disabled)
	CMinionStuart(const CMinionStuart &) = delete;

	virtual ~CMinionStuart();

	virtual void Accept(CGameVisitor * visitor) { }
};

