/**
 * \file Villain.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "Villain.h"


 /**
 * Constructor
 * \param game The game we are in
 * \param filename Filename for the image we use
 */
CVillain::CVillain(CGame *game, const std::wstring &filename, int const pointMult) : CItem(game, filename)
{
	mPointMult = pointMult;
}


CVillain::~CVillain()
{
}
