#pragma once
#include "stdafx.h"
#include "Game.h"

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

