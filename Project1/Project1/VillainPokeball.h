/**
 * \file VillainPokeball.h
 *
 * \author Hector
 *
 * Class for the Pokeball Villain 
 */

#pragma once
#include "Villain.h"
#include "Item.h"

/**
* The class for the Pokeball villain
*/
class CVillainPokeball :
	public CVillain
{
public:
	CVillainPokeball(CGame * game);

	CVillainPokeball() = delete;

	CVillainPokeball(const CVillainPokeball &) = delete;

	virtual ~CVillainPokeball();

	virtual void Accept(CGameVisitor * visitor) { visitor->VisitPokeeball(this); }
};

