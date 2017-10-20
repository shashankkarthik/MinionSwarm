/**
 * \file GetScoreVisitor.cpp
 *
 * \author Team Hector
 * The visitor that manages the score
 */

#include "stdafx.h"
#include "GetScoreVisitor.h"
#include "VillainJuicer.h"
#include "VillainPokeball.h"
#include "VillainArya.h"

/**
* Constructor
*/
CGetScoreVisitor::CGetScoreVisitor()
{
}

/**
* Destructor
*/
CGetScoreVisitor::~CGetScoreVisitor()
{
}


/**
 * Visits Juicer object to retrieve score
 * \param juicer pointer to Juicer object
 */
void CGetScoreVisitor::VisitJuicer(CVillainJuicer *juicer)
{
	mScoreMap["Juicer"] = juicer->GetScore();
}


/**
 * Visits Pokeeball object to retrieve score
 * \param pokeeball pointer to Pokeeball object
 */
void CGetScoreVisitor::VisitPokeeball(CVillainPokeball *pokeeball)
{
	mScoreMap["Pokeeball"] = pokeeball->GetScore();
}


/**
 * Visits Arya object to retrieve score
 * \param arya pointer to Arya object
 */
void CGetScoreVisitor::VisitArya(CVillainArya *arya)
{
	mScoreMap["Arya"] = arya->GetScore();
}