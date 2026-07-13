// CImportExportTab.cpp : implementation file
//

#include "pch.h"
#include "BookManagement.h"
#include "afxdialogex.h"
#include "CImportExportTab.h"


// CImportExportTab dialog

IMPLEMENT_DYNAMIC(CImportExportTab, CDialogEx)

CImportExportTab::CImportExportTab(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CImportExportTab, pParent)
{

}

CImportExportTab::~CImportExportTab()
{
}

void CImportExportTab::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CImportExportTab, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_EXPORT, &CImportExportTab::OnBnClickedBtnExport)
	ON_BN_CLICKED(IDC_BTN_IMPORT, &CImportExportTab::OnBnClickedBtnImport)
	ON_BN_CLICKED(IDC_BTN_BROWSE, &CImportExportTab::OnBnClickedBtnBrowse)
END_MESSAGE_MAP()


// CImportExportTab message handlers

void CImportExportTab::OnBnClickedBtnExport()
{
	// TODO: Add your control notification handler code here
}

void CImportExportTab::OnBnClickedBtnImport()
{
	// TODO: Add your control notification handler code here
}

void CImportExportTab::OnBnClickedBtnBrowse()
{
	// TODO: Add your control notification handler code here
}
