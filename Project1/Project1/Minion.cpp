/**
 * \file Minion.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "Minion.h"
#include "GameVisitorMinion.h"
#include <vector>



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
void CMinion::Flock(CVector cohesionCenter, int numberMinions, CVector alignemnt)
{
	av = alignemnt;

	double lengthav = av.Length();
	if (lengthav > 0)
	{
		av.Normalize();
	}
	cv = cohesionCenter - GetLocation();
	double l = cv.Length();
	if (l > 0)
	{
		cv /= l;
	}





	mV = cv * 1 + av * 5; //+ sv * 3 + av * 5 + gruV * 10;
	double lengthmv = mV.Length();
	if (lengthmv > 0)
	{
		mV.Normalize();
	}
}

CVector CMinion::Alignment(std::vector<CMinion *> minionVector)
{
	CVector totalVelocity;
	int count = 0;
	for (auto i = minionVector.begin(); i != minionVector.end(); ++i)
	{
		if (GetLocation().Distance((*i)->GetLocation()) < 200)
		{
			totalVelocity += (*i)->GetSpeed();
			count++;
		}

	}
	if (count == 0)
	{
		count = 1;
	}
	return (totalVelocity / count);

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