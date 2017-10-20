/**
 * \file VillainPokeball.cpp
 *
 * \author Hector
 * 
 * Class for the Pokeball villain
 */

#include "stdafx.h"
#include <string>
#include "VillainPokeball.h"


using namespace std;
using namespace Gdiplus;

/// image filename 
const wstring VillainPokeballImageName = L"images/pokeball.png";

/// Point multiplier
const int PointsMult = 3;



/** Constructor
* \param game The game this is a member of
*/
CVillainPokeball::CVillainPokeball(CGame *game) : CVillain(game, VillainPokeballImageName, PointsMult)
{
}


/**
* Destructor
*/
CVillainPokeball::~CVillainPokeball()
{
}
