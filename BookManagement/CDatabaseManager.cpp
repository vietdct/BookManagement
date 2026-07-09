#include "pch.h"
#include "CDatabaseManager.h"

CDatabaseManager& CDatabaseManager::GetInstance()
{
	static CDatabaseManager instance;
	return instance;
}
CDatabaseManager::CDatabaseManager() : m_isConnected(false)
{
}

CDatabaseManager::~CDatabaseManager()
{
	Disconnect();
}



bool CDatabaseManager::Connect() {
	if (m_isConnected) { return true; }

	CString connectionStr =
		L"DRIVER={ODBC Driver 18 for SQL Server};"
		L"SERVER=(localdb)\\MSSQLLocalDB;"
		L"DATABASE=BookManagementDB;"
		L"Trusted_Connection=Yes;"
		L"Encrypt=no;";
	TRY
	{
		m_database.OpenEx(connectionStr, CDatabase::noOdbcDialog);
		m_isConnected = true;
	}
		CATCH(CDBException, e) {
		CString msg;
		msg.Format(L"Database connection failed: %s", e->m_strError.GetString());
		AfxMessageBox(msg);
		m_isConnected = false;
	}
	END_CATCH

		return m_isConnected;
};
void CDatabaseManager::Disconnect()
{
	if (m_isConnected && m_database.IsOpen())
	{
		m_isConnected = false;
		m_database.Close();
	}
};

CDatabase* CDatabaseManager::GetDatabase()
{
	return &m_database;
}
