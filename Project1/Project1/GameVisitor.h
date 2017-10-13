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


class CGameVisitor
{
public:
	CGameVisitor();
	virtual ~CGameVisitor();


	virtual void VisitJuicer(CVillainJuicer * Juicer) {};
	virtual void VisitPokeeball(CVillainPokeball * pokeeball) {};
	virtual void VisitArya(CVillainArya * arya) {};
};

