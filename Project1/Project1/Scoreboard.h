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
	void CScoreboard::DrawImage(Gdiplus::Graphics * graphics, unique_ptr<Bitmap> image, float xLoc, float yLoc);
private:
	unique_ptr<Gdiplus::Bitmap> mJuicerImage;
	unique_ptr<Gdiplus::Bitmap> mPokeeballImage;
	unique_ptr<Gdiplus::Bitmap> mAryaImage;

	int mJuicerScore;
	int mPokeeballScore;
	int mArayaScore;


};

