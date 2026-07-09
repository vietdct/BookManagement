#pragma once
#include "afxdialogex.h"
#include "BookService.h"

// CBookTab dialog
//Tab 1: Book Management UI
// Ke thua CDialogEx nhung vao CTabCtrl cua CMainFormView 
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
	//	afx_msg void OnEnChangeEditName();
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEditName3();

	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnUpdate();
	afx_msg void OnBnClickedBtnDelete();
	afx_msg void OnBnClickedBtnClear();
	afx_msg void OnLvnItemchangedListBooks(NMHDR* pNMHDR, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()
private:
	BookService m_service;  //Tab chi goi service, Khong tu goi Repository
	int m_selectedId;		// ID cua dong tren list duoc chon 
	void RefreshList();		// Load toan bo data tu service len CListCtrl
	void ClearForm();
	bool GetFormInput(CString& name, double& price, int& quantity, CString& errorMsg);

public:
	CString m_editName;
	CString m_editPrice;
	CString m_editQty;
	CListCtrl m_listBooks;

};
