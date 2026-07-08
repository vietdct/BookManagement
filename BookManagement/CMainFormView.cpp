// CMainFormView.cpp : implementation file
//

#include "pch.h"
#include "BookManagement.h"
#include "CMainFormView.h"
#include "afxdialogex.h"


// CMainFormView

IMPLEMENT_DYNCREATE(CMainFormView, CFormView)

CMainFormView::CMainFormView()
	: CFormView(IDD_CMainFormView)
{

}

CMainFormView::~CMainFormView()
{
}

void CMainFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MAIN, m_tabCtrl);
}

BEGIN_MESSAGE_MAP(CMainFormView, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN,&CMainFormView::OnTcnSelchangeTabMain)
END_MESSAGE_MAP()

// OnInitialUpdate chay sau khi toan bo view duoc tao xong
// Cac Tab con nhung vao CTabCtrl
void CMainFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	//Add 2 title Tab vao trong CTabCtrl
	m_tabCtrl.InsertItem(0, L"Book Management");
	m_tabCtrl.InsertItem(1, L"Import / Export ");

	//Vung hien thi trong Tab Control ( tru header )
	CRect tabRect;
	m_tabCtrl.GetClientRect(&tabRect);
	m_tabCtrl.AdjustRect(false, &tabRect); //Vung hien thi content ( tru header )

	//Tao 2 dialog con nhung vao ben trong tab control
	m_bookTab.Create(IDD_CBookTab, &m_tabCtrl);
	m_bookTab.MoveWindow(&tabRect);

	m_importExportTab.Create(IDD_CImportExportTab, &m_tabCtrl);
	m_importExportTab.MoveWindow(&tabRect);

	//Default : hien Tab 1 , An Tab 2
	switchToTab(0);
}
// An/Hien dung tab dang duoc chon ( 2 dialog con luon ton tai chi an hien qua showWindown
void CMainFormView::switchToTab(int index)
{
	m_bookTab.ShowWindow(index == 0 ? SW_SHOW : SW_HIDE);
	m_importExportTab.ShowWindow(index == 1 ? SW_SHOW : SW_HIDE);
}

// xu li khi client bam doi tab tren CTabCtrl
void CMainFormView::OnTcnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult)
{
	int selectedTab = m_tabCtrl.GetCurSel();
	switchToTab(selectedTab);
	*pResult = 0;
}

// CMainFormView diagnostics

#ifdef _DEBUG
void CMainFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMainFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMainFormView message handlers
