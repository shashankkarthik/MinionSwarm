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

using namespace Gdiplus;
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/// Frame duration in milliseconds
const int FrameDuration = 30;
/// Any item we are currently dragging
std::shared_ptr<CItem> mGrabbedItem;

// CChildView

/**
* Constructor
*/
CChildView::CChildView()
{
	auto gru = make_shared<CGru>(&mGame);
	gru->SetLocation(-300,300);
	mGame.Add(gru);

	auto villainArya = make_shared<CVillainArya>(&mGame);
	villainArya->SetLocation(75, 200);
	mGame.Add(villainArya);

	auto villainJuicer = make_shared<CVillainJuicer>(&mGame);
	villainJuicer->SetLocation(-175, -250);
	mGame.Add(villainJuicer);

}

/**
* Destructor
*/
CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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
	mGame.HitTest(point.x, point.y);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CWnd::OnLButtonUp(nFlags, point);
}
