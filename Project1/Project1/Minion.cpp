/**
 * \file Minion.cpp
 *
 * \author Hector
 */

#include "stdafx.h"
#include "Minion.h"
#include "GameVisitorMinion.h"
#include <vector>


/// Cohesion weight
const int CohesionWeight = 1;

/// Separation weight
const int SeparationWeight = 3;

/// Alignment weight
const int AlignmentWeight = 5;

/// Gru weight
const int GruWeight = 10;

/// Default closest distance
const double DefaultDistance = 1000000000000;

/// Alignment radius
const int AlignmentRadius = 200;

/// Prevent divide by zero
const int PreventDivideByZero = 1;

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
		mV = cv * CohesionWeight + av * AlignmentWeight + sv * SeparationWeight;
	}
	else
	{
		mV = cv * CohesionWeight + av * AlignmentWeight + gruV * GruWeight + sv * SeparationWeight;
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
	double dist = DefaultDistance;

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
		if (GetLocation().Distance((*i)->GetLocation()) < AlignmentRadius)
		{
			totalVelocity += (*i)->GetSpeed();
			count++;
		}

	}
	if (count == 0)
	{
		count = PreventDivideByZero;
	}
	return (totalVelocity / count);

}

CVector CMinion::Separation(std::vector<CMinion *> minionVector)
{
	CVector SeparationVector;
	double distance = DefaultDistance;
	double temp_dist = DefaultDistance;
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
	CVector newP = GetLocation() + mV * elapsed * mSpeed;


	SetLocation(newP.X(), newP.Y());
}


CVector CMinion::GetCohesion()
{
	CGameVisitorMinion visitor;
	GetGameTiles()->Accept(&visitor);
	CVector center = visitor.CohesionCenter() / visitor.NumberMinions();
	return center;
}