/**
 * \file Minion.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "Minion.h"
#include "GameVisitorMinion.h"


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
//this is flocking
void CMinion::Flock(CVector cohesionCenter, int numberMinions)
{
	cv = cohesionCenter - GetLocation();
	double l = cv.Length();
	if (l > 0)
	{
		cv /= l;
	}





	mV = cv * 1; //+ sv * 3 + av * 5 + gruV * 10;
	double lengthmv = mV.Length();
	if (lengthmv > 0)
	{
		mV.Normalize();
	}	
}

void CMinion::Move(double elapsed)
{
	CVector test;
	test.Set(1,2);
	CVector newP = GetLocation() + mV * elapsed * 300;
	//CVector newP = GetLocation() + test * elapsed * 300;


	SetLocation(newP.X(), newP.Y());
}


CVector CMinion::GetCohesion()
{
	CGameVisitorMinion visitor;
	GetGameTiles()->Accept(&visitor);
	CVector center = visitor.CohesionCenter() / visitor.NumberMinions();
	return center;
}