/**
 * \file PlayingArea.h
 *
 * \author Team Hector
 *
 * Playing Area class that creates the box
 */

#pragma once
#include "stdafx.h"
#include "Game.h"

/**
* Playing Area class that creates the box
*/
class CPlayingArea 
{
public:
	CPlayingArea();
	virtual ~CPlayingArea();

	const static double GridSize;
	const static double GridRadius;
	const static double GridMargin;

	void DrawArea(Gdiplus::Graphics *graphics, int gameWidth, int gameHeight);
};

