/**
 * \file VillainArya.cpp
 *
 * \author Hector
 * Arya villain class 
 */

#include "stdafx.h"
#include <string>
#include "VillainArya.h"


using namespace std;
using namespace Gdiplus;

/// image filename 
const wstring VillainAryaImageName = L"images/arya.png";

/// Point multiplier
const int PointsMult = 1;



/** Constructor
* \param game The game this is a member of
*/
CVillainArya::CVillainArya(CGame *game) : 
	CVillain(game, VillainAryaImageName, PointsMult)
{
}


/**
* Destructor
*/
CVillainArya::~CVillainArya()
{
}

