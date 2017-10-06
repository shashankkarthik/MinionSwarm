/**
 * \file MinionStuart.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "MinionStuart.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring MinionStuartImageName = L"images/stuart.png";
const int points = 1;


/** Constructor
* \param aquarium The aquarium this is a member of
*/
CMinionStuart::CMinionStuart(CGame *game) :
	CMinion(game, MinionStuartImageName, points)
{
}


/**
* Destructor
*/
CMinionStuart::~CMinionStuart()
{
}