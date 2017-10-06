/**
 * \file VillainArya.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "VillainArya.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring VillainAryaImageName = L"images/arya.png";
const int pointsMult = 1;



/** Constructor
* \param aquarium The aquarium this is a member of
*/
CVillainArya::CVillainArya(CGame *game) : CVillain(game, VillainAryaImageName, pointsMult)
{
}


/**
* Destructor
*/
CVillainArya::~CVillainArya()
{
}
