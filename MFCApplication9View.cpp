
// MFCApplication9View.cpp : implementation of the CMFCApplication9View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication9.h"
#endif

#include "MFCApplication9Doc.h"
#include "MFCApplication9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CHcnmau.h"
#include"CQuanco.h"
#include"CQuancoT.h"
#include"CQuancoI.h"
#include"CQuancoL.h"
#include"CQuancoV.h"
#include"CQuancoH1.h"
#include"CQuancoH2.h"
#include"CBanco.h"
#include "CBanco.h"

// CMFCApplication9View

IMPLEMENT_DYNCREATE(CMFCApplication9View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication9View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFCApplication9View construction/destruction

CMFCApplication9View::CMFCApplication9View() noexcept
{
	// TODO: add construction code here

}

CMFCApplication9View::~CMFCApplication9View()
{
}

BOOL CMFCApplication9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication9View drawing

void CMFCApplication9View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pdc(this);
	//CHcnmau hcn = CHcnmau(0, 0, 50, 50, 255, 0, 0);
	//hcn.draw(&pdc);
	//CQuanco* p = new CQuancoH2(50, 50);
	//p->draw(&pdc);
	CBanco banco = CBanco();
	banco.draw(&pdc);
	// TODO: add draw code for native data here
}

void CMFCApplication9View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication9View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication9View diagnostics

#ifdef _DEBUG
void CMFCApplication9View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication9Doc* CMFCApplication9View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication9Doc)));
	return (CMFCApplication9Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication9View message handlers

UINT newThreadProc(LPVOID pParam)
{
	CMFCApplication9View* view = (CMFCApplication9View*)pParam;
	view->playgame();
	return 1;
}
void CMFCApplication9View::playgame()
{
	CClientDC pdc(this);
	banco.play(&pdc);
}
void CMFCApplication9View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	banco.start();
	CClientDC pdc(this);
	banco.draw(&pdc);
	//std::thread th4 (CBanco::play, & banco, & pDC);
	//th4.detach();
	//th4.join();
	//banco.play(&pDC);
	AfxBeginThread(newThreadProc, this);
	CView::OnRButtonDown(nFlags, point);
}
 

void CMFCApplication9View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CClientDC pdc(this);
	// TODO: Add your message handler code here and/or call default
	if (nChar == 37)
	{
		banco.goLeft(&pdc);
	}
	if (nChar == 40)
	{
		banco.goDown(&pdc);
	}
	if (nChar == 39)
	{
		banco.goRight(&pdc);
	}
	if (nChar == 38)
	{
		banco.rotate(&pdc);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
