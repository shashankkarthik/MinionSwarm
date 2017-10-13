#pragma once
#include <memory>
#include <string>

using namespace std;
using namespace Gdiplus;


class CScoreboard
{
public:
	CScoreboard();
	virtual	~CScoreboard();
	void CScoreboard::DrawScore(Gdiplus::Graphics * graphics, float xLoc, float yLoc, std::wstring score);
	void Draw(Graphics * graphics, int gameWidth, int gameHeight);
	
private:

	unique_ptr<Bitmap> mJuicerImage;
	unique_ptr<Bitmap> mPokeeballImage;
	unique_ptr<Bitmap> mAryaImage;

	int mJuicerScore;
	int mPokeeballScore;
	int mArayaScore;
};

