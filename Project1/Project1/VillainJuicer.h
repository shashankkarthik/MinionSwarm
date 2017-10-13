/**
 * \file VillainJuicer.h
 *
 * \author Hector
 *
 * Juicer is a Villain
 */

#pragma once
#include "Villain.h"
#include "Item.h"

class CVillainJuicer :
	public CVillain
{
public:
	CVillainJuicer(CGame * game);

	/// Default constructor (disabled)
	CVillainJuicer() = delete;

	/// Copy constructor (disabled)
	CVillainJuicer(const CVillainJuicer &) = delete;

	virtual ~CVillainJuicer();

	virtual void Accept(CGameVisitor * visitor) { visitor->VisitJuicer(this); }
};

