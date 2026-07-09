#include "pch.h"
#include "CBookRecordSet.h"

IMPLEMENT_DYNAMIC(CBookRecordSet, CRecordset)

CBookRecordSet::CBookRecordSet(CDatabase* pDatabase)
	: CRecordset(pDatabase) {
	m_ID = 0;
	m_NAME = _T("");
	m_PRICE = 0.0;
	m_QUANTITY = 0;
	m_CREATED_DATE = CTime::GetCurrentTime();

	m_nFields = columnCount;
	m_nDefaultType = snapshot; // snapshot : Update/Edit in recordset is allowed
}

CString CBookRecordSet::GetDefaultConnect() 
{
	// vi connection duoc CDatabaseManager quan li va truyen vao constructor cua CBookRecordSet nen khong can connect lai
	return L"ODBC;";
}

CString CBookRecordSet::GetDefaultSQL()
{
	return L"SELECT ID , NAME , PRICE , QTY , CREATED_DATE FROM BOOK";
}

//MFC goi ham DoFieldExchange de dong bo cac field trong recordset voi cac field trong database 
void CBookRecordSet::DoFieldExchange(CFieldExchange* pFX)
{
	// Mac dinh la bind cac field theo thu tu trong SQL query
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Double(pFX, _T("[PRICE]"), m_PRICE);
	RFX_Long(pFX, _T("[QTY]"), m_QUANTITY);
	RFX_Date(pFX, _T("[CREATED_DATE]"), m_CREATED_DATE);
}

#ifdef _DEBUG
void CBookRecordSet::AssertValid() const {
	CRecordset::AssertValid();
}
void CBookRecordSet::Dump(CDumpContext& dc) const {
	CRecordset::Dump(dc);
}
#endif // _DEBUG
