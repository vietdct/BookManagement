#pragma once
#include "afxdialogex.h"


// CImportExportTab dialog

class CImportExportTab : public CDialogEx
{
	DECLARE_DYNAMIC(CImportExportTab)

public:
	CImportExportTab(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CImportExportTab();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CImportExportTab };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnExport();
	afx_msg void OnBnClickedBtnImport();
	afx_msg void OnBnClickedBtnBrowse();
};
