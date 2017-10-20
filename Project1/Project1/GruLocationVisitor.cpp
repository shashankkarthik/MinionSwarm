#include "stdafx.h"
#include "GruLocationVisitor.h"


CGruLocationVisitor::CGruLocationVisitor()
{
}


CGruLocationVisitor::~CGruLocationVisitor()
{
}

void CGruLocationVisitor::VisitGru(CGru * gru)
{
	double mGruX = gru->CItem::GetLocation().X();
	double mGruY = gru->CItem::GetLocation().Y();
	mGruLocation.Set(mGruX, mGruY);
}


