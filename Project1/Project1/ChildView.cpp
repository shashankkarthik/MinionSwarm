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

using namespace Gdiplus;
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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
	CPaintDC paintDC(this);     // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting

	Graphics graphics(dc.m_hDC);

	CRect rect;
	GetClientRect(&rect);

	mGame.OnDraw(&graphics, rect.Width(), rect.Height()); //still need mGame object

	//mGame

	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}



BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}

/**
* Called when there is a left mouse button press
* \param nFlags Flags associated with the mouse button press
* \param point Where the button was pressed
*/
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	/* This should be the code once we have the Hit test working
	mGrabbedItem = mGame.HitTest(point.x, point.y);
	if (mGrabbedItem != nullptr)
	{

		//mGame.MoveToBack(mGrabbedItem); //we might not need this depending on the design
	}*/
}

