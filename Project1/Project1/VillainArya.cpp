/**
 * \file VillainArya.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include <string>
#include "VillainArya.h"


using namespace std;
using namespace Gdiplus;

/// image filename 
const wstring VillainAryaImageName = L"images/arya.png";
const int pointsMult = 1;



/** Constructor
* \param game The game this is a member of
*/
CVillainArya::CVillainArya(CGame *game) : 
	CVillain(game, VillainAryaImageName, pointsMult)
{
}


/**
* Destructor
*/
CVillainArya::~CVillainArya()
{
}

