#pragma once
#include <afxdb.h>
class CBookRecordSet : public CRecordset
{
public:
	CBookRecordSet(CDatabase* pDatabase = nullptr);
	DECLARE_DYNAMIC(CBookRecordSet)

	//Map truc tiep voi fields trong database
	long m_ID;
	CString m_NAME;
	double m_PRICE;
	long m_QUANTITY;
	CTime m_CREATED_DATE;


// field count for CBookRecordSet
enum {columnCount = 5};

public:
	virtual CString GetDefaultConnect(); // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL query
	virtual void DoFieldExchange(CFieldExchange* pFX); // Declare RFX support de bind fields to recordset


#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif // _DEBUG


};