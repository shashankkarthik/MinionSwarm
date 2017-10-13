#include "stdafx.h"
#include "Scoreboard.h"


using namespace std;
using namespace Gdiplus;

const wstring JuicerImageName = L"images/juicer.png";
const wstring PokeeballImageName = L"images/pokeball.png";
const wstring AryaImageName = L"images/arya.png";

CScoreboard::CScoreboard()
{
}


CScoreboard::~CScoreboard()
{
}

void CScoreboard::DrawScore(Gdiplus::Graphics * graphics, float xLoc, float yLoc, wstring score)
{
	score = score + L"\0";
	WCHAR* string = (WCHAR *)score.c_str();
	Gdiplus::Font myFont(L"Arial", 16);
	RectF layoutRect(xLoc, yLoc, 50.0f, 50.0f);
	StringFormat format;
	format.SetAlignment(StringAlignmentCenter);
	SolidBrush greenBrush(Color(255, 0, 255, 0));

	graphics->DrawString(
		string,
		-1,
		&myFont,
		layoutRect,
		&format,
		&greenBrush);

}



void CScoreboard::Draw(Graphics * graphics, int Width, int Height) 
{

	mJuicerImage = unique_ptr<Bitmap>(Bitmap::FromFile(JuicerImageName.c_str()));
	if (mJuicerImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += JuicerImageName;
		AfxMessageBox(msg.c_str());
	}

	graphics->DrawImage(mJuicerImage.get(), float((Width - 240) / 2.0), -float((Height - 300) / 2.0));
	DrawScore(graphics, float((Width - 200) / 2.0), -float((Height - 600) / 2.0), L"0");

	mPokeeballImage = unique_ptr<Bitmap>(Bitmap::FromFile(PokeeballImageName.c_str()));
	if (mPokeeballImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += PokeeballImageName;
		AfxMessageBox(msg.c_str());
	}

	graphics->DrawImage(mPokeeballImage.get(), float((Width - 200) / 2.0), -float((Height - 700) / 2.0));
	DrawScore(graphics, float((Width - 200) / 2.0), -float((Height - 800) / 2.0), L"0");

	mAryaImage = unique_ptr<Bitmap>(Bitmap::FromFile(AryaImageName.c_str()));
	if (mAryaImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += AryaImageName;
		AfxMessageBox(msg.c_str());
	}

	graphics->DrawImage(mAryaImage.get(), float((Width - 275) / 2.0), -float((Height - 900) / 2.0));
	DrawScore(graphics, float((Width - 200) / 2.0), -float((Height - 1200) / 2.0), L"0");

}