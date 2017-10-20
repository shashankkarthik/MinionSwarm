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

 /**
 * The class for the villain Arya
 */
class CVillainArya : 
	public CVillain
{
public:
	CVillainArya(CGame *game);

	CVillainArya() = delete;

	CVillainArya(const CVillainArya &) = delete;

	virtual ~CVillainArya();

	virtual void Accept(CGameVisitor * visitor) { visitor->VisitArya(this); }
};

