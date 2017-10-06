/**
 * \file CMinionMutant.h
 *
 * \author Hector
 *
 * Mutant Minion
 */

#pragma once
#include "Minion.h"
class CMinionMutant :
	public CMinion
{
public:
	CMinionMutant(CGame * game);

	/// Default constructor (disabled)
	CMinionMutant() = delete;

	/// Copy constructor (disabled)
	CMinionMutant(const CMinionMutant &) = delete;

	virtual ~CMinionMutant();
};

