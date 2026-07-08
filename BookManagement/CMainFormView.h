#pragma once
#include "CBookTab.h"
#include "CImportExportTab.h"

// CMainFormView form view — chua CTabCtrl, nhung 2 Tab con (CBookTab, CImportExportTab)
class CMainFormView : public CFormView
{
	

protected:
	CMainFormView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMainFormView)

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CMainFormView };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // goi sau khi view duoc tao xong, noi tao cac tab con
	afx_msg void OnTcnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()
public:
	virtual ~CMainFormView();
#ifndef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif // !_WIN32_WCE

#endif // _DEBUG

private:
	CTabCtrl m_tabCtrl;
	CBookTab m_bookTab;					// tab 1:
	CImportExportTab m_importExportTab;	// tab 2:
	
	void switchToTab(int index);		// an/hien dung tab dang chon
};


