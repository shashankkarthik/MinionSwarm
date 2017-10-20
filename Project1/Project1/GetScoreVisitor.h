/**
 * \file GetScoreVisitor.h
 *
 * \author Team Hector
 *
 * Concrete visitor that tracks score
 */

#pragma once
#include <map>
#include "GameVisitor.h"

using namespace std;


/**
* Concrete visitor that tracks and calculates score
*/
class CGetScoreVisitor :
	public CGameVisitor
{
public:
	CGetScoreVisitor();
	~CGetScoreVisitor();

	virtual void VisitJuicer(CVillainJuicer *juicer);
	virtual void VisitPokeeball(CVillainPokeball * pokeeball);
	virtual void VisitArya(CVillainArya *arya);

	map<string, int> GenerateScoreMap() { return mScoreMap; }
private:

	/// Maps the score 
	map<string, int> mScoreMap;
};

