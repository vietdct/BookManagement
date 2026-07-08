
// BookManagementView.cpp : implementation of the CBookManagementView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "BookManagement.h"
#endif

#include "BookManagementDoc.h"
#include "BookManagementView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBookManagementView

IMPLEMENT_DYNCREATE(CBookManagementView, CView)

BEGIN_MESSAGE_MAP(CBookManagementView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBookManagementView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CBookManagementView construction/destruction

CBookManagementView::CBookManagementView() noexcept
{
	// TODO: add construction code here

}

CBookManagementView::~CBookManagementView()
{
}

BOOL CBookManagementView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CBookManagementView drawing

void CBookManagementView::OnDraw(CDC* /*pDC*/)
{
	CBookManagementDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CBookManagementView printing


void CBookManagementView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBookManagementView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBookManagementView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBookManagementView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CBookManagementView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBookManagementView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBookManagementView diagnostics

#ifdef _DEBUG
void CBookManagementView::AssertValid() const
{
	CView::AssertValid();
}

void CBookManagementView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBookManagementDoc* CBookManagementView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBookManagementDoc)));
	return (CBookManagementDoc*)m_pDocument;
}
#endif //_DEBUG


// CBookManagementView message handlers
