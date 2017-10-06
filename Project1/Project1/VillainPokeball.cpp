/**
 * \file VillainPokeball.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "VillainPokeball.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring VillainPokeballImageName = L"images/pokeball.png";
const int pointsMult = 3;



/** Constructor
* \param aquarium The aquarium this is a member of
*/
CVillainPokeball::CVillainPokeball(CGame *game) : CVillain(game, VillainPokeballImageName, pointsMult)
{
}


/**
* Destructor
*/
CVillainPokeball::~CVillainPokeball()
{
}
