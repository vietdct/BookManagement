// CBookTab.cpp : implementation file


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
	, m_selectedId(0)

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


//-----------------------------INIT---------------------------------
BOOL CBookTab::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//Thiet lap cot cho CListCtrl
	m_listBooks.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_listBooks.InsertColumn(0, L"ID", LVCFMT_LEFT, 50);
	m_listBooks.InsertColumn(1, L"NAME", LVCFMT_LEFT, 300);
	m_listBooks.InsertColumn(2, L"PRICE", LVCFMT_RIGHT, 150);
	m_listBooks.InsertColumn(3, L"QTY", LVCFMT_RIGHT, 100);
	m_listBooks.InsertColumn(4, L"CREATED_DATE", LVCFMT_LEFT, 400);
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
		m_listBooks.SetItemData(row, b.GetId());

	}
}

//------------------- Lay du lieu tu form + validate dinh dang co ban ----------------
bool CBookTab::GetFormInput(CString& name, double& price, int& quantity, CString& errorMsg)
{
	UpdateData(true);
	name = m_editName;

	if (m_editPrice.IsEmpty() || m_editQty.IsEmpty())
	{
		errorMsg = L"Please enter the full Price and Quantity.";
		return false;
	}
	price = _ttof(m_editPrice);
	quantity = _ttoi(m_editQty);
	return true;
}

//---------------------------- Del form --------------------------------
void CBookTab::ClearForm()
{
	m_editName.Empty();
	m_editPrice.Empty();
	m_editQty.Empty();
	m_selectedId = 0;
	m_listBooks.SetItemState(-1, 0, LVIS_SELECTED);
	UpdateData(false);
}

//------------------- ADD -------------------

void CBookTab::OnBnClickedBtnAdd()
{
	CString name, errorMsg;
	double price;
	int quantity;

	if (!GetFormInput(name, price, quantity ,errorMsg))
	{
		AfxMessageBox(errorMsg);
		return;
	}
	if (!m_service.AddBook(name, price, quantity, errorMsg))
	{
		AfxMessageBox(errorMsg);
		return;
	}
	RefreshList();
	ClearForm();
	AfxMessageBox(L" Add Book Is Successed.");
}

void CBookTab::OnBnClickedBtnUpdate()
{
	CString name, errorMsg;
	double price;
	int quantity;

	if (m_selectedId == 0)
	{
		AfxMessageBox(L"Please select a row from the list to update.");
		return;
	}
	if (!GetFormInput(name, price, quantity, errorMsg)) {
		AfxMessageBox(errorMsg);
		return;
	}
	if (!m_service.UpdateBook(m_selectedId,name, price, quantity, errorMsg)) {
		AfxMessageBox(errorMsg);
		return;
	}
	RefreshList();
	ClearForm();
	AfxMessageBox(L"Update Book Is Successed.");
}

void CBookTab::OnBnClickedBtnDelete()
{
	if (m_selectedId == 0) 
	{
		AfxMessageBox(L"Please select a row from the list to delete.");
		return;
	}
	int result = AfxMessageBox(L"Are you sure you want to delete this book?",
								MB_YESNO | MB_ICONQUESTION);
	if (result != IDYES) return;
	CString errorMsg;
	if (!m_service.DeleteBook(m_selectedId, errorMsg))
	{
		AfxMessageBox(errorMsg);
		return;
	}

	RefreshList();
	ClearForm();
	AfxMessageBox(L"Deleted Book Is Successed .");
}

void CBookTab::OnBnClickedBtnClear()
{
	ClearForm();
}

void CBookTab::OnLvnItemchangedListBooks(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	if ((pNMLV->uChanged & LVIF_STATE) && (pNMLV->uNewState & LVIS_SELECTED))
	{
		int nSelected = pNMLV->iItem;
		m_selectedId = (int)m_listBooks.GetItemData(nSelected);

		// Nếu form dùng DDX (m_name, m_price, m_quantity là member variable)
		m_editName = m_listBooks.GetItemText(nSelected, 1); // cột tương ứng
		m_editPrice =(m_listBooks.GetItemText(nSelected, 2));
		m_editQty = (m_listBooks.GetItemText(nSelected, 3));
		UpdateData(FALSE); // đẩy dữ liệu member -> control trên dialog
	}
	*pResult = 0;
}
