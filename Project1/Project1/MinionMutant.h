/**
 * \file CMinionMutant.h
 *
 * \author Hector
 *
 * Mutant Minion class 
 */

#pragma once
#include "Minion.h"

/** 
*Class for the Mutant Minion
*/
class CMinionMutant :
	public CMinion
{
public:
	CMinionMutant(CGame * game);

	CMinionMutant() = delete;

	CMinionMutant(const CMinionMutant &) = delete;

	virtual ~CMinionMutant();

	virtual void Accept(CGameVisitor * visitor) { visitor->VisitMinionMutant(this); }
};

