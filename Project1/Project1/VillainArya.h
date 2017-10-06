/**
 * \file VillainArya.h
 *
 * \author Hector
 *
 * Arya is a villain
 */

#pragma once
#include "Villain.h"
#include "Item.h"

class CVillainArya : public CVillain
{
public:
	CVillainArya(CGame * game);

	/// Default constructor (disabled)
	CVillainArya() = delete;

	/// Copy constructor (disabled)
	CVillainArya(const CVillainArya &) = delete;

	virtual ~CVillainArya();
};

