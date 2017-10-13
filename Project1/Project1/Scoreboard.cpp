#include "stdafx.h"
#include "Scoreboard.h"
#include <map>
#include <iostream>


using namespace std;
using namespace Gdiplus;

/// Juicer filename
const wstring JuicerImageName = L"images/juicer.png";

/// Juicer X padding
const int JuicerImageXPad = 240;

/// Juicer Y padding
const int JuicerImageYPad = 300;

/// Juicer score Y padding
const int JuicerScoreYPad = 600;



/// Pokeeball filename
const wstring PokeeballImageName = L"images/pokeball.png";

/// Pokeeball X Pad
const int PokeballImageXPad = 200;

/// Pokeball Y Pad
const int PokeballImageYPad = 700;

/// Pokeball score Y padding
const int PokeballScoreYPad = 800;



/// Arya filename
const wstring AryaImageName = L"images/arya.png";

/// Arya X padding
const int AryaImageXPad = 275;

/// Arya Y padding
const int AryaImageYPad = 900;

/// Arya Score Y padding
const int AryaScoreYPad = 1200;


/// Score X padding
const int ScoreXPad = 200;

/// Font size
const int ScoreFontSize = 16;

/// Score rect width
const float RectWidth = 50.0f;

/// Score rect height
const float RectHeight = 50.0f;

/// Text Color
const Color TextColor = Color(255, 0, 255, 0);

CScoreboard::CScoreboard()
{
	mJuicerImage = unique_ptr<Bitmap>(Bitmap::FromFile(JuicerImageName.c_str()));
	if (mJuicerImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += JuicerImageName;
		AfxMessageBox(msg.c_str());
	}

	mPokeeballImage = unique_ptr<Bitmap>(Bitmap::FromFile(PokeeballImageName.c_str()));
	if (mPokeeballImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += PokeeballImageName;
		AfxMessageBox(msg.c_str());
	}

	mAryaImage = unique_ptr<Bitmap>(Bitmap::FromFile(AryaImageName.c_str()));
	if (mAryaImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += AryaImageName;
		AfxMessageBox(msg.c_str());
	}

	initializeScoreMap();

}


CScoreboard::~CScoreboard()
{
}


/**
 * Draw score text
 * \param graphics Graphics devices to draw on
 * \param xLoc X coordinate to draw at
 * \param yLoc Y coordinate to draw at
 * \param score Score to draw
 */
void CScoreboard::DrawScore(Gdiplus::Graphics * graphics, float xLoc, float yLoc, int scoreInt)
{	
	///Draws rectangle to surround text
	wstring score = to_wstring(scoreInt);
	score = score + L"\0";
	WCHAR* string = (WCHAR *)score.c_str();
	Gdiplus::Font myFont(L"Arial", 16);
	RectF layoutRect(xLoc, yLoc, RectWidth, RectHeight);
	StringFormat format;
	format.SetAlignment(StringAlignmentCenter);
	SolidBrush greenBrush(TextColor);

	///Draws string in rectangle
	graphics->DrawString(
		string,
		-1,
		&myFont,
		layoutRect,
		&format,
		&greenBrush);

}



/**
 * Draws image and related score
 * \param graphics Graphic device to draw on.
 * \param Width Window width
 * \param Height Window height
 */
void CScoreboard::Draw(Graphics * graphics, int Width, int Height) 
{

	
	graphics->DrawImage(mJuicerImage.get(), float((Width - JuicerImageXPad) / 2.0), -float((Height - JuicerImageYPad) / 2.0));
	DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - JuicerScoreYPad) / 2.0), mScoreMap["Juicer"]);

	

	graphics->DrawImage(mPokeeballImage.get(), float((Width - PokeballImageXPad) / 2.0), -float((Height - PokeballImageYPad) / 2.0));
	DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - PokeballScoreYPad) / 2.0), mScoreMap["Pokeeball"]);


	graphics->DrawImage(mAryaImage.get(), float((Width - AryaImageXPad) / 2.0), -float((Height - AryaImageYPad) / 2.0));
	DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - AryaScoreYPad) / 2.0), mScoreMap["Arya"]);

}


void CScoreboard::initializeScoreMap()
{
	mScoreMap["Juicer"] = 0;
	mScoreMap["Pokeeball"] = 0;
	mScoreMap["Arya"] = 0;
}
