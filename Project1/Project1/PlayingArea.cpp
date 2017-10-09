#include "stdafx.h"
#include "Game.h"
#include "PlayingArea.h"

using namespace Gdiplus;

/// The size of the playing area square in virtual pixels
const double CPlayingArea::GridSize = 1000.0;

/// The range from the center to an edge for the playing area
/// in virtual pixels
const double CPlayingArea::GridRadius = CPlayingArea::GridSize / 2.0;

/// Do not allow Minions or Gru to come closer than this distance
/// to the playing area edges (virtual pixels)
const double CPlayingArea::GridMargin = 50.0;


CPlayingArea::CPlayingArea()
{
}


CPlayingArea::~CPlayingArea()
{
}

void CPlayingArea::DrawArea(Gdiplus::Graphics *graphics, int gameWidth, int gameHeight)
{
	Pen greenPen(Color(0, 64, 0), 3);
	graphics->DrawRectangle(&greenPen,
		float(-(gameWidth - GridSize / 2.0) / 2.0),
		float((gameWidth/2.0 - (GridSize/2.0))),
		GridSize, 
		GridSize);
}
