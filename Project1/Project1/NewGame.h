#pragma once
#include <memory>
#include "GameVisitor.h"

class CNewGame : public CGameVisitor
{
public:
	CNewGame();
	virtual ~CNewGame();
	void Draw(Gdiplus::Graphics * graphics, int windowWidth, int windowHeight);

	bool HitTest(int x, int y);

private:
	std::unique_ptr<Gdiplus::Bitmap> mButtonImage;
	float mX = 0;
	float mY = 0;
};

