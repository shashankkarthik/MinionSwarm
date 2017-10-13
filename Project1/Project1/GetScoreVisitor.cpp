#include "stdafx.h"
#include "GetScoreVisitor.h"
#include "VillainJuicer.h"
#include "VillainPokeball.h"
#include "VillainArya.h"

CGetScoreVisitor::CGetScoreVisitor()
{
}


CGetScoreVisitor::~CGetScoreVisitor()
{
}

void CGetScoreVisitor::VisitJuicer(CVillainJuicer *juicer)
{
	mScoreMap["Juicer"] = juicer->GetScore();
}

void CGetScoreVisitor::VisitPokeeball(CVillainPokeball *pokeeball)
{
	mScoreMap["Pokeeball"] = pokeeball->GetScore();
}

void CGetScoreVisitor::VisitArya(CVillainArya *arya)
{
	mScoreMap["Arya"] = arya->GetScore();
}