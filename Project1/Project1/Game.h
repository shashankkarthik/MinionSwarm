#pragma once
class CGame
{
public:

	CGame();

	virtual ~CGame();

	void CGame::OnDraw(Gdiplus::Graphics *graphics, int width, int height);


private:
	float mScale = 0;
	float mXOffset = 0;
	float mYOffset = 0;


};

