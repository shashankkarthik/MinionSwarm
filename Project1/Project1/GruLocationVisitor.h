#pragma once
#include "GameVisitor.h"
#include "Vector.h"
#include "Game.h"
#include "Gru.h"



class CGruLocationVisitor
	:public CGameVisitor
{
public:
	CGruLocationVisitor();
	~CGruLocationVisitor();

	
	void VisitGru(CGru * gru);

	const CVector GetGruLocation() { return mGruLocation; }
	

private:
	CVector mGruLocation;
	double mGruX;
	double mGruY;
};

