#pragma once
#include <memory>
#include <string>
#include <map>

using namespace std;
using namespace Gdiplus;


class CScoreboard
{
public:
	CScoreboard();
	virtual	~CScoreboard();

	void Draw(Graphics * graphics, int gameWidth, int gameHeight);
	
	map<string, int> GetScoreMap() { return mScoreMap; }
	void SetScoreMap(map<string, int> newScoreMap) { mScoreMap = newScoreMap; }
	
	
private:

	void initializeScoreMap();
	void DrawScore(Gdiplus::Graphics * graphics, float xLoc, float yLoc, int scoreInt);


	map<string, int> mScoreMap;

	unique_ptr<Bitmap> mJuicerImage;
	unique_ptr<Bitmap> mPokeeballImage;
	unique_ptr<Bitmap> mAryaImage;

};

