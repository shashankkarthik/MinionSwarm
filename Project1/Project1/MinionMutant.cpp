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

/// Value of minion
const int Points = 5;

/// Speed of minion
const int MinionSpeed = 300;

/** Constructor
* \param game The game this is a member of
*/
CMinionMutant::CMinionMutant(CGame *game) :
	CMinion(game, MinionMutantImageName, Points, MinionSpeed)
{
}


/**
* Destructor
*/
CMinionMutant::~CMinionMutant()
{
}