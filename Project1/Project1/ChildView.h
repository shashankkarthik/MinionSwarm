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

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};
