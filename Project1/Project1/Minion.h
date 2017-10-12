/**
 * \file Minion.h
 *
 * \author Hector
 *
 * Base minion class
 */

#pragma once
#include "Item.h"
class CMinion : public CItem
{
protected:
	CMinion(CGame * game, const std::wstring & filename, int const points);

public:
	virtual ~CMinion();

	/// Default constructor (disabled)
	CMinion() = delete;

	/// Copy constructor (disabled)
	CMinion(const CMinion &) = delete;

	///Get points for the minion
	int GetPoints() { return mPoints; }

private:
	/// Fish speed in the X direction
	double mSpeedX = 0;

	/// Fish speed in the Y direction
	double mSpeedY = 0;

	///Points if you kill minion
	int mPoints = 0;
};

