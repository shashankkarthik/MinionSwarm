/**
 * \file Scoreboard.h
 *
 * \author Team Hector
 *
 * 
 */

#pragma once
#include <memory>
#include <string>
#include <map>
#include <vector>

using namespace std;
using namespace Gdiplus;

/**
* The class for the scoreboard and contains the villain score objects
*/
class CScoreboard
{
public:
	CScoreboard();
	virtual	~CScoreboard();

	void Draw(Graphics * graphics, int gameWidth, int gameHeight);
	
	map<string, int> GetScoreMap() { return mScoreMap; }
	void SetScoreMap(map<string, int> newScoreMap) { mScoreMap = newScoreMap; }
	
	
private:

	
	void InitializeScoreMap();
	void GenerateNonZero();
	void DetermineConfig();
	bool Find(string x);
	void DrawScore(Gdiplus::Graphics * graphics, float xLoc, float yLoc, int scoreInt);

	///Maps the score and name 
	map<string, int> mScoreMap;

	/// Image for the Juicer score
	unique_ptr<Bitmap> mJuicerImage;
	
	/// Image for the Pokeeball score
	unique_ptr<Bitmap> mPokeeballImage;

	/// Image for the Arya score
	unique_ptr<Bitmap> mAryaImage;

	vector<string> mNonZero;

	int mConfig;

};

