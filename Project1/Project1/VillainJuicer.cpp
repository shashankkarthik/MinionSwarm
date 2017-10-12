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

/// image filename 
const wstring VillainJuicerImageName = L"images/juicer.png";
const int pointsMult = 2;



/** Constructor
* \param game The game this is a member of
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
