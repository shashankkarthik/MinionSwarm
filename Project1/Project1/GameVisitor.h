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
class CMinionJerry;
class CMinionStuart;
class CMinionMutant;
class CGru;


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
	virtual void VisitMinionJerry(CMinionJerry * minion) {};

	virtual void VisitMinionMutant(CMinionMutant * minion) {};

	virtual void VisitMinionStuart(CMinionStuart * minion) {};

	virtual void VisitGru(CGru * gru) {};

};

