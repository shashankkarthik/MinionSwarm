/**
 * \file GameVisitor.h
 *
 * \author Hector
 *
 * This is the Visitor base class, that will visit our collection of GameTiles.
 */

#pragma once

class CVillainJuicer;
class CVillainPokeball;
class CVillainArya;
class CMinion;


class CGameVisitor
{
public:
	CGameVisitor();
	virtual ~CGameVisitor();

	///Visits juicer object
	virtual void VisitJuicer(CVillainJuicer * Juicer) {};

	///Visits pokeeball object
	virtual void VisitPokeeball(CVillainPokeball * pokeeball) {};

	///Visits arya object
	virtual void VisitArya(CVillainArya * arya) {};

	///Visits minion object
	virtual void VisitMinion(CMinion * minion) {};
};

