/**
 * \file Gru.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "Gru.h"
#include <string>


using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring GruImageName = L"images/gru.png";

/** Constructor
* \param aquarium The aquarium this is a member of
*/
CGru::CGru(CGame *game) :
	CItem(game, GruImageName)
{
}


/**
* Destructor
*/
CGru::~CGru()
{
}