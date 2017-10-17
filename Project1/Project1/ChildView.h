/**
* \file ChildView.h
*
* \author Team Hector
*
* Class that implements the child window our program draws in.
*
* The window is a child of the main frame, which holds this
* window, the menu bar, and the status bar.
*/

// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Game.h"

// CChildView window
/**
* The child window our program draws in.
*/
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	void ResetScreen();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);


private:
	CGame mGame;

	/// True until the first time we draw
	bool mFirstDraw = true;
	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates

	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

