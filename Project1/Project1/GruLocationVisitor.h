/**
 * \file GruLocationVisitor.h
 *
 * \author Team Hector
 *
 * Concrete visitor class that visits and tracks Gru
 */

#pragma once
#include "GameVisitor.h"
#include "Vector.h"
#include "Game.h"
#include "Gru.h"


/**
* Concrete visitor that controls/tracks Gru
*/
class CGruLocationVisitor
	:public CGameVisitor
{
public:
	CGruLocationVisitor();
	~CGruLocationVisitor();

	
	void VisitGru(CGru * gru);

	const CVector GetGruLocation() { return mGruLocation; }
	

private:

	/// Gru's velocity vector
	CVector mGruLocation;

	/// Gru's x location
	double mGruX;

	/// Gru's y location 
	double mGruY;
};

