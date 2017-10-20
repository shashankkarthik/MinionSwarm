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

/// image filename 
const wstring MinionJerryImageName = L"images/jerry.png";
/// Value of minion
const int Points = 1;


/** Constructor
* \param game The game this is a member of
*/
CMinionJerry::CMinionJerry(CGame *game) :
	CMinion(game, MinionJerryImageName, Points)
{
}


/**
* Destructor
*/
CMinionJerry::~CMinionJerry()
{
}