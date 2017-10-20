/**
* \file ChildView.cpp
*
* \author Team Hector
*/

// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Project1.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"
#include "Game.h"
#include "VillainJuicer.h"
#include "Villain.h"
#include "Item.h"
#include <memory>
#include "Villain.h"
#include "Item.h"
#include "Gru.h"
#include <string>
#include "VillainArya.h"
#include "VillainPokeball.h"

using namespace Gdiplus;
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/// Frame duration in milliseconds
const int FrameDuration = 30;
/// Any item we are currently dragging
std::shared_ptr<CItem> mGrabbedItem;
/// Arya's X location
const int AryaXLocation = 75;
/// Arya's Y location
const int AryaYLocation = 200;
/// Juicer's X location
const int JuicerXLocation = -200;
/// Juicer's Y location
const int JuicerYLocation = -250;
/// Pokeball's X location
const int PokeballXLocation = 275;
/// Pokeball's Y location
const int PokeballYLocation = -250;
/// Gru's X location
const int GruXLocation = -300;
/// Gru's Y location
const int GruYLocation = 300;

// CChildView

/**
* Constructor
*/
CChildView::CChildView()
{
	ResetScreen(); //clears the screen and adds the villains and gru
	srand((unsigned int)time(nullptr));
}

/**
* Destructor
*/
CChildView::~CChildView()
{

}

void CChildView::ResetScreen()
{
	mGame.Delete();

	auto villainArya = make_shared<CVillainArya>(&mGame);
	villainArya->SetLocation(AryaXLocation, AryaYLocation);
	mGame.Add(villainArya);

	auto villainJuicer = make_shared<CVillainJuicer>(&mGame);
	villainJuicer->SetLocation(JuicerXLocation, JuicerYLocation);
	mGame.Add(villainJuicer);

	auto villainPokeball = make_shared<CVillainPokeball>(&mGame);
	villainPokeball->SetLocation(PokeballXLocation, PokeballYLocation);
	mGame.Add(villainPokeball);

	auto gru = make_shared<CGru>(&mGame);
	gru->SetLocation(GruXLocation, GruYLocation);
	mGame.Add(gru);

}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CChildView message handlers

/** This function is called before the window is created.
* \param cs A structure with the window creation parameters
* \returns TRUE
*/
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

/** This function is called to draw in the window.
*
* This function is called in response to a drawing message
* whenever we need to redraw the window on the screen.
* It is responsible for painting the window.
*/
void CChildView::OnPaint() 
{
	// Do not call CWnd::OnPaint() for painting messages

	CPaintDC paintDC(this);     // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting

	Graphics graphics(dc.m_hDC);

	CRect rect;
	GetClientRect(&rect);

	mGame.OnDraw(&graphics, rect.Width(), rect.Height()); //still need mGame object

	//mGame

	// TODO: Add your message handler code here
	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		/*
		* Initialize the elapsed time system
		*/
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}

	if (mGame.GetResetStatus()) {
		ResetScreen();
		mGame.SetResetStatus(false);
	}

	/*
	* Compute the elapsed time since the last draw
	*/
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	mGame.Update(elapsed);

}



BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (!mGame.HitTestNewGame(point.x, point.y))
	{
		mGrabbedItem = mGame.HitTestGru(point.x, point.y);
	};
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	OnMouseMove(nFlags, point);
	//CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// See if an item is currently being moved by the mouse
	if (mGrabbedItem != nullptr)
	{
		// If an item is being moved, we only continue to 
		// move it while the left button is down.
		if (nFlags & MK_LBUTTON)
		{
			//Changes the x and y value and sets location
			float virtualX = (point.x - mGame.GetmXOffset()) / mGame.GetmScale();
			float virtualY = (point.y - mGame.GetmYOffset()) / mGame.GetmScale();
			mGrabbedItem->SetLocation(virtualX, virtualY);
		}
		else
		{
			// When the left button is released, we release the
			// item.
			mGrabbedItem = nullptr;
		}

		// Force the screen to redraw
		Invalidate();
	}
	//CWnd::OnMouseMove(nFlags, point);
}
