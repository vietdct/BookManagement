// CBookTab.cpp : implementation file
//

#include "pch.h"
#include "BookManagement.h"
#include "afxdialogex.h"
#include "CBookTab.h"
#include "BookService.h"

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
//-----------------------------INIT---------------------------------
BOOL CBookTab::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//Thiet lap cot cho CListCtrl
	m_listBooks.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_listBooks.InsertColumn(0, L"ID", LVCFMT_LEFT, 50);
	m_listBooks.InsertColumn(1, L"NAME", LVCFMT_LEFT, 180);
	m_listBooks.InsertColumn(2, L"PRICE", LVCFMT_RIGHT, 90);
	m_listBooks.InsertColumn(3, L"QTY", LVCFMT_RIGHT, 70);
	m_listBooks.InsertColumn(4, L"CREATED_DATE", LVCFMT_LEFT, 120);
	RefreshList();
	return true;
}

//RefreshList ( sau moi lan Update/Add ...)
void CBookTab::RefreshList()
{
	m_listBooks.DeleteAllItems();
	std::vector<Book> books = m_service.GetAllBooks();
	for (size_t i = 0; i < books.size(); i++) {
		const Book& b = books[i];

		CString idStr, priceStr, qtyStr;
		idStr.Format(L"%d", b.GetId());
		priceStr.Format(L"%.2f", b.GetPrice());
		qtyStr.Format(L"%d", b.GetQuantity());

		int row = m_listBooks.InsertItem(i, idStr);
		m_listBooks.SetItemText(row, 1, b.GetName());
		m_listBooks.SetItemText(row, 2, priceStr);
		m_listBooks.SetItemText(row, 3, qtyStr);
		m_listBooks.SetItemText(row, 4, b.GetCreatedDate());

	}
}
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
