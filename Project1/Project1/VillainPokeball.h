/**
 * \file VillainPokeball.h
 *
 * \author Hector
 *
 * PokeBall is a Villain
 */

#pragma once
#include "Villain.h"
#include "Item.h"

class CVillainPokeball :
	public CVillain
{
public:
	CVillainPokeball(CGame * game);

	/// Default constructor (disabled)
	CVillainPokeball() = delete;

	/// Copy constructor (disabled)
	CVillainPokeball(const CVillainPokeball &) = delete;

	virtual ~CVillainPokeball();

	virtual void Accept(CGameVisitor * visitor) { visitor->VisitPokeeball(this); }
};

