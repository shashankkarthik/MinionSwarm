/**
 * \file Villain.cpp
 *
 * \author Hector
 * The base class for the villain objects
 */

#include "stdafx.h"
#include<string>
#include "Villain.h"

using namespace std;

 /**
 * Constructor
 * \param game The game we are in
 * \param filename Filename for the image we use
 * \param pointMult The point multiplier for the villain
 */
CVillain::CVillain(CGame *game, const std::wstring &filename, int const pointMult) : 
	CItem(game, filename)
{
	mPointMult = pointMult;
}


CVillain::~CVillain()
{
}


