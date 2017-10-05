/**
 * \file Villain.h
 *
 * \author Hector
 *
 * Villain 
 */

#pragma once
#include "Item.h"
class CVillain :
	public CItem
{
public:
	CVillain();
	virtual ~CVillain();

private:
	int mPoints = 0;
	int mPointMult = 0;
};

