/**
 * \file Minion.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "Minion.h"


 /**
 * Constructor
 * \param game The game we are in
 * \param filename Filename for the image we use
 */
CMinion::CMinion(CGame *game, const std::wstring &filename, int const points) :
	CItem(game, filename)
{
	mPoints = points;
}


CMinion::~CMinion()
{
}
