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

 /**
 * The class for the Juicer villain 
 */
class CVillainJuicer :
	public CVillain
{
public:
	CVillainJuicer(CGame * game);

	CVillainJuicer() = delete;

	CVillainJuicer(const CVillainJuicer &) = delete;

	virtual ~CVillainJuicer();

	virtual void Accept(CGameVisitor * visitor) { visitor->VisitJuicer(this); }
};

