/**
 * \file VillainJuicer.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "VillainJuicer.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring VillainJuicerImageName = L"images/juicer.png";
const int pointsMult = 2;



/** Constructor
* \param aquarium The aquarium this is a member of
*/
CVillainJuicer::CVillainJuicer(CGame *game) : CVillain(game, VillainJuicerImageName, pointsMult)
{
}


/**
* Destructor
*/
CVillainJuicer::~CVillainJuicer()
{
}
