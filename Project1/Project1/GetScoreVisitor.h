#pragma once
#include "GameVisitor.h"
#include <map>

using namespace std;


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
	map<string, int> mScoreMap;
};

