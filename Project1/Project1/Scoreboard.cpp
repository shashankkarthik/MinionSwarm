#include "stdafx.h"
#include "Scoreboard.h"
#include <map>
#include <iostream>
#include <vector>


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

	InitializeScoreMap();
	mConfig = 0;

	
	

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
	DetermineConfig();
	switch (mConfig)
	{
		case 0:
			break;
		case 1:
			graphics->DrawImage(mJuicerImage.get(), float((Width - JuicerImageXPad) / 2.0), -float((Height - JuicerImageYPad) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - JuicerScoreYPad) / 2.0), mScoreMap["Juicer"]);


			graphics->DrawImage(mPokeeballImage.get(), float((Width - PokeballImageXPad) / 2.0), -float((Height - PokeballImageYPad) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - PokeballScoreYPad) / 2.0), mScoreMap["Pokeeball"]);


			graphics->DrawImage(mAryaImage.get(), float((Width - AryaImageXPad) / 2.0), -float((Height - AryaImageYPad) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - AryaScoreYPad) / 2.0), mScoreMap["Arya"]);
			
			break;
		case 2:
			graphics->DrawImage(mJuicerImage.get(), float((Width - JuicerImageXPad) / 2.0), -float((Height - JuicerImageYPad) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - JuicerScoreYPad) / 2.0), mScoreMap["Juicer"]);


			graphics->DrawImage(mPokeeballImage.get(), float((Width - PokeballImageXPad) / 2.0), -float((Height - PokeballImageYPad) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - PokeballScoreYPad) / 2.0), mScoreMap["Pokeeball"]);
			break;
		
		case 3:
			graphics->DrawImage(mJuicerImage.get(), float((Width - JuicerImageXPad) / 2.0), -float((Height - JuicerImageYPad) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - JuicerScoreYPad) / 2.0), mScoreMap["Juicer"]);

			graphics->DrawImage(mAryaImage.get(), float((Width - AryaImageXPad) / 2.0), -float((Height - (AryaImageYPad-200)) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - (AryaScoreYPad-200)) / 2.0), mScoreMap["Arya"]);
			break;
		case 4:
			graphics->DrawImage(mPokeeballImage.get(), float((Width - PokeballImageXPad) / 2.0), -float((Height - (PokeballImageYPad-400)) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - (PokeballScoreYPad-400)) / 2.0), mScoreMap["Pokeeball"]);

			graphics->DrawImage(mAryaImage.get(), float((Width - AryaImageXPad) / 2.0), -float((Height - (AryaImageYPad - 350)) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - (AryaScoreYPad - 350)) / 2.0), mScoreMap["Arya"]);
			break;

		case 5:
			graphics->DrawImage(mJuicerImage.get(), float((Width - JuicerImageXPad) / 2.0), -float((Height - JuicerImageYPad) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - JuicerScoreYPad) / 2.0), mScoreMap["Juicer"]);
			break;
		case 6:
			graphics->DrawImage(mPokeeballImage.get(), float((Width - PokeballImageXPad) / 2.0), -float((Height - (PokeballImageYPad - 400)) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - (PokeballScoreYPad - 400)) / 2.0), mScoreMap["Pokeeball"]);
			break;
		case 7:
			graphics->DrawImage(mAryaImage.get(), float((Width - AryaImageXPad) / 2.0), -float((Height - (AryaImageYPad - 600)) / 2.0));
			DrawScore(graphics, float((Width - ScoreXPad) / 2.0), -float((Height - (AryaScoreYPad - 600)) / 2.0), mScoreMap["Arya"]);
			break;


	}
	
	

}


void CScoreboard::InitializeScoreMap()
{
	mScoreMap["Juicer"] = 0;
	mScoreMap["Pokeeball"] = 0;
	mScoreMap["Arya"] = 0;
}


void  CScoreboard::GenerateNonZero()
{	
	mNonZero.clear();
	for (auto const& villain : mScoreMap)
	{
		if (villain.second > 0)
		{
			mNonZero.push_back(villain.first);
		}
	}
}


void CScoreboard::DetermineConfig()
{
	GenerateNonZero();
	switch (mNonZero.size())
	{
		case 3:
			mConfig = 1;
			break;
		case 2:
			if (Find("Juicer") && Find("Pokeeball"))
			{
				mConfig = 2;
			}
			else if (Find("Juicer") && Find("Arya"))
			{
				mConfig = 3;
			}
			else if (Find("Pokeeball") && Find("Arya"))
			{
				mConfig = 4;
			}
			break;
		case 1:
			if (Find("Juicer"))
			{
				mConfig = 5;
			}
			else if (Find("Pokeeball"))
			{
				mConfig = 6;
			}
			else if (Find("Arya"))
			{
				mConfig = 7;
			}
			break;
		case 0: 
			mConfig = 0;
			break;
	}
	
	
	
}



bool CScoreboard::Find(string x)
{
	
	
	if (find(mNonZero.begin(),mNonZero.end(), x) != mNonZero.end()) 
	{
		return true;
	}
	else {
		return false;
	}
}


