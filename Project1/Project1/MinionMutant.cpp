/**
 * \file CMinionMutant.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "MinionMutant.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// image filename 
const wstring MinionMutantImageName = L"images/mutant.png";
const int points = 5;


/** Constructor
* \param game The game this is a member of
*/
CMinionMutant::CMinionMutant(CGame *game) :
	CMinion(game, MinionMutantImageName, points)
{
}


/**
* Destructor
*/
CMinionMutant::~CMinionMutant()
{
}