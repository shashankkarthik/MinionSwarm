/**
 * \file GameVisitor.h
 *
 * \author Hector
 *
 * This is the Visitor base class, that will visit our collection of GameTiles.
 */

#pragma once

class CVillain;

class CGameVisitor
{
public:
	CGameVisitor();
	virtual ~CGameVisitor();


	virtual void VisitVillain(CVillain * villain) {};
};

