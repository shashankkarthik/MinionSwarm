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
CMinion::CMinion(CGame *game, const std::wstring &filename, int const points, double speed) :
	CItem(game, filename)
{
	mPoints = points;
	mSpeed = speed;
}


CMinion::~CMinion()
{
}
//this is flocking
void CMinion::Flock(CVector cohesionCenter, int numberMinions, CVector alignemnt, CVector mGruLocation, bool mGameOver, CVector Separation)
{
	av = alignemnt;
	sv = GetLocation() - Separation;

	double lengthsv = sv.Length();
	if (lengthsv > 0)
	{
		sv.Normalize();
	}

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


	gruV = mGruLocation - GetLocation();

	if (mGameOver) 
	{
		mV = cv * 1 + av * 5 + sv * 3;
	}
	else
	{
		mV = cv * 1 + av * 5 + gruV * 10 + sv * 3;
	}
	double lengthmv = mV.Length();
	if (lengthmv > 0)
	{
		mV.Normalize();
	}
}

CVector CMinion::FindClosest(std::vector<CMinion*> minionVector)
{
	CVector result;
	double dist = 1000000000000;

	for (auto minion : minionVector)
	{
		double temp_dist = minion->GetLocation().Distance(this->GetLocation());
		if (temp_dist < dist && temp_dist != 0)
		{
			dist = temp_dist;
			result = minion->GetLocation();
		}
	}

	return result;
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

CVector CMinion::Separation(std::vector<CMinion *> minionVector)
{
	CVector SeparationVector;
	double distance = 99999999999;
	double temp_dist = 999999999;
	for (auto i = minionVector.begin(); i != minionVector.end(); ++i)
	{
		temp_dist = GetLocation().Distance((*i)->GetLocation());
		if (temp_dist < distance && temp_dist > .01)
		{
			distance = temp_dist;
			SeparationVector = (*i)->GetLocation();
		}

	}

	return (SeparationVector);

}

void CMinion::Move(double elapsed)
{
	CVector test;
	test.Set(1,2);
	CVector newP = GetLocation() + mV * elapsed * mSpeed;
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