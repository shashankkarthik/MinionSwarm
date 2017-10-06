/**
 * \file MinionJerry.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "MinionJerry.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring MinionJerryImageName = L"images/jerry.png";
const int points = 1;


/** Constructor
* \param aquarium The aquarium this is a member of
*/
CMinionJerry::CMinionJerry(CGame *game) :
	CMinion(game, MinionJerryImageName, points)
{
}


/**
* Destructor
*/
CMinionJerry::~CMinionJerry()
{
}