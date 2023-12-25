
// MFCApplication9View.h : interface of the CMFCApplication9View class
//

#pragma once
#include"CBanco.h"
#include<thread>


class CMFCApplication9View : public CView
{
protected: // create from serialization only
	CMFCApplication9View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication9View)

// Attributes
public:
	CMFCApplication9Doc* GetDocument() const;

// Operations
public:
	CBanco banco;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMFCApplication9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void playgame();
};

#ifndef _DEBUG  // debug version in MFCApplication9View.cpp
inline CMFCApplication9Doc* CMFCApplication9View::GetDocument() const
   { return reinterpret_cast<CMFCApplication9Doc*>(m_pDocument); }
#endif

