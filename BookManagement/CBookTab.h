#pragma once
#include "afxdialogex.h"


// CBookTab dialog

class CBookTab : public CDialogEx
{
	DECLARE_DYNAMIC(CBookTab)

public:
	CBookTab(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CBookTab();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CBookTab };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnEnChangeEditName();
	afx_msg void OnEnChangeEditName3();
	CString m_editName;
	CString m_editPrice;
	CString m_editQty;
	CListCtrl m_listBooks;
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnUpdate();
	afx_msg void OnBnClickedBtnDelete();
	afx_msg void OnBnClickedBtnClear();
	afx_msg void OnLvnItemchangedListBooks(NMHDR* pNMHDR, LRESULT* pResult);
};
