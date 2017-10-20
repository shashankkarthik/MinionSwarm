/**
 * \file Minion.h
 *
 * \author Hector
 *
 * Base minion class
 */

#pragma once
#include "Item.h"
#include <vector>

class CMinion : public CItem
{
protected:
	CMinion(CGame * game, const std::wstring & filename, int const points, double speed = 150);

public:
	virtual ~CMinion();

	virtual void Flock(CVector cohesionCenter, int numberMinions, CVector alignemnt, CVector mGruLocation, bool mGameOver);

	void Move(double elapsed);

	CVector GetCohesion();

	/// Default constructor (disabled)
	CMinion() = delete;

	/// Copy constructor (disabled)
	CMinion(const CMinion &) = delete;

	///Get points for the minion
	int GetPoints() { return mPoints; }

	int GetLevel() { return 1; };

	CVector GetSpeed() { return mV; }

	virtual CVector Alignment(std::vector<CMinion *> minionVector);



private:
	/// Minion speed 
	double mSpeed = 150;

	///Points if you kill minion
	int mPoints = 0;

	// Cohesion vector
	CVector cv;

	// Separation vector
	CVector sv;

	// Alignment vector
	CVector av;

	// Gru vector
	CVector gruV;

	/// Velocity in virtual pixels/second
	CVector mV;

};

