// CBookTab.cpp : implementation file
//

#include "pch.h"
#include "BookManagement.h"
#include "afxdialogex.h"
#include "CBookTab.h"


// CBookTab dialog

IMPLEMENT_DYNAMIC(CBookTab, CDialogEx)

CBookTab::CBookTab(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CBookTab, pParent)
	, m_editName(_T(""))
	, m_editPrice(_T(""))
	, m_editQty(_T(""))
{

}

CBookTab::~CBookTab()
{
}

void CBookTab::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Text(pDX, IDC_EDIT_PRICE, m_editPrice);
	DDX_Text(pDX, IDC_EDIT_QTY, m_editQty);
	DDX_Control(pDX, IDC_LIST_BOOKS, m_listBooks);
}


BEGIN_MESSAGE_MAP(CBookTab, CDialogEx)
//	ON_EN_CHANGE(IDC_EDIT_NAME, &CBookTab::OnEnChangeEditName)
	ON_BN_CLICKED(IDC_BTN_ADD, &CBookTab::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_UPDATE, &CBookTab::OnBnClickedBtnUpdate)
	ON_BN_CLICKED(IDC_BTN_DELETE, &CBookTab::OnBnClickedBtnDelete)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CBookTab::OnBnClickedBtnClear)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_BOOKS, &CBookTab::OnLvnItemchangedListBooks)
END_MESSAGE_MAP()


// CBookTab message handlers

//void CBookTab::OnEnChangeEditName()
//{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
//}

void CBookTab::OnBnClickedBtnAdd()
{
	// TODO: Add your control notification handler code here
}

void CBookTab::OnBnClickedBtnUpdate()
{
	// TODO: Add your control notification handler code here
}

void CBookTab::OnBnClickedBtnDelete()
{
	// TODO: Add your control notification handler code here
}

void CBookTab::OnBnClickedBtnClear()
{
	// TODO: Add your control notification handler code here
}

void CBookTab::OnLvnItemchangedListBooks(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
