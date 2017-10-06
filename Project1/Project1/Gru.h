/**
 * \file Gru.h
 *
 * \author Hector
 *
 * Gru is a piece that shouldn't die
 */

#pragma once
#include "Item.h"
class CGru : public CItem
{
protected:
	CGru(CGame * game);

public:
	virtual ~CGru();

	/// Default constructor (disabled)
	CGru() = delete;

	/// Copy constructor (disabled)
	CGru(const CGru &) = delete;
};

