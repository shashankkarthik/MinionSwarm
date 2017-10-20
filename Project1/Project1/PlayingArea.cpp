#include "stdafx.h"
#include "Game.h"
#include "PlayingArea.h"
#include "ChildView.h"
#include "Game.h"

using namespace Gdiplus;

/// The size of the playing area square in virtual pixels
const double CPlayingArea::GridSize = 1000.0;

/// The range from the center to an edge for the playing area
/// in virtual pixels
const double CPlayingArea::GridRadius = CPlayingArea::GridSize / 2.0;

/// Do not allow Minions or Gru to come closer than this distance
/// to the playing area edges (virtual pixels)
const double CPlayingArea::GridMargin = 50.0;

/// Green value for color of pen
const int GreenValue = 64;

///Three for pen
const int Three = 3;

/// X location of top left corner
const int GridXLocation = 500;

/// Y location of top left corner
const int GridYLocation = 100;

CPlayingArea::CPlayingArea()
{
}


CPlayingArea::~CPlayingArea()
{
}

void CPlayingArea::DrawArea(Gdiplus::Graphics *graphics, int windowWidth, int windowHeight)
{
	Pen greenPen(Color(0, GreenValue, 0), Three);
	graphics->DrawRectangle(&greenPen,
		float((-windowWidth + GridXLocation) / 2.0),
		float((-windowHeight + GridYLocation) / 2.0),
		float(GridSize),
		float(GridSize));

}
