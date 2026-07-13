#include "pch.h"
#include "BookRepository.h"
#include "CBookRecordSet.h"
#include "CDatabaseManager.h"
//chua sql query truc tiep

BookRepository::BookRepository()
{
}

// Get all books from the database
std::vector<Book> BookRepository::GetAllBooks()
{
	std::vector<Book> result;
	CDatabase* pDB = CDatabaseManager::GetInstance().GetDatabase();

	TRY
	{
		CBookRecordSet rs(pDB);
		rs.Open(); //use default SQL query to get all books (Sekect * from Book)
		while (!rs.IsEOF())
		{
			Book book(
				(int)rs.m_ID,
				rs.m_NAME,
				rs.m_PRICE,
				(int)rs.m_QUANTITY,
				rs.m_CREATED_DATE.Format(_T("%Y-%m-%d %H:%M:%S")));
			result.push_back(book);
			rs.MoveNext();
		}
		rs.Close();
	}
		CATCH(CDBException, e)
	{
		AfxMessageBox(_T("Database error: ") + e->m_strError);
	}
	END_CATCH
		return result;
}

// Insert a new book into the database
bool BookRepository::InsertBook( Book& book)
{
	CDatabase* pDB = CDatabaseManager::GetInstance().GetDatabase();
	bool success = true;
	
	TRY
	{
		CBookRecordSet rs(pDB);
		//mo voi dk rong de lay cau truc table khong can load data
		rs.Open(CRecordset::dynaset, L"SELECT * FROM BOOK WHERE 1=0");
		rs.AddNew(); // add new record
		rs.m_NAME = book.GetName();
		rs.m_PRICE = book.GetPrice();
		rs.m_QUANTITY = book.GetQuantity();
		// k set id ( auto increment) , set created date = current date
		rs.Update(); // create query to insert new record into database
		rs.Close();
	}
		CATCH(CDBException,e)
	{
		AfxMessageBox(_T("Database error: ") + e->m_strError);
		success = false;
	}
	END_CATCH
		return success;
}

// Update 
bool BookRepository::UpdateBook(const Book& book)
{
	CDatabase* pDB = CDatabaseManager::GetInstance().GetDatabase();
	bool success = true;
	TRY
	{
		CBookRecordSet rs(pDB);
		CString sql;
		sql.Format(_T("SELECT * FROM Book WHERE ID = %d"), book.GetId());
		rs.Open(CRecordset::dynaset, sql);

		if (!rs.IsEOF())
		{
			rs.Edit(); // Edit the current record
			rs.m_NAME = book.GetName();
			rs.m_PRICE = book.GetPrice();
			rs.m_QUANTITY = book.GetQuantity();
			rs.m_CREATED_DATE = CTime::GetCurrentTime();
			rs.Update(); // Update the record in the database
		}
		else 
		{
			success = false; // id not found update failed
		}
		rs.Close();
	}
		CATCH(CDBException, e)
	{
		AfxMessageBox(_T("Database error when update: ") + e->m_strError);
		success = false;
	}
	END_CATCH
		return success;
}

// Delete 
bool BookRepository::DeleteBook(int id)
{
	CDatabase* pDB = CDatabaseManager::GetInstance().GetDatabase();
	bool success = true;

	TRY
	{
		CBookRecordSet rs(pDB);
		CString sql;
		sql.Format(_T("SELECT * FROM Book WHERE ID = %d"), id);
		rs.Open(CRecordset::dynaset, sql);
		if (!rs.IsEOF())
		{
			rs.Delete(); // Delete the current record
		}
		else
		{
			success = false; // id not found delete failed
		}
		rs.Close();
	}
		CATCH(CDBException, e)
	{
		AfxMessageBox(_T("Database error when delete: ") + e->m_strError);
		success = false;
	}
	END_CATCH
		return success;
}

//SearchBookByName 
std::vector<Book> BookRepository::SearchBookByName(const CString& nameBook)
{
	std::vector<Book> result;
	CString safeName = nameBook;
	safeName.Replace(L"'", L"''");
	CDatabase* pDB = CDatabaseManager::GetInstance().GetDatabase();
	TRY
	{
		CBookRecordSet rs(pDB);
		CString sql;
		sql.Format(_T("SELECT * FROM Book WHERE NAME LIKE '%%%s%%'"), safeName.GetString());
		rs.Open(CRecordset::dynaset, sql);

		while (!rs.IsEOF())
		{
			Book book(
				(int)rs.m_ID,
				rs.m_NAME,
				rs.m_PRICE,
				(int)rs.m_QUANTITY,
				rs.m_CREATED_DATE.Format(_T("%Y-%m-%d")));
			result.push_back(book);
			rs.MoveNext();
		}
		rs.Close();
	}
		CATCH(CDBException, e)
	{
		AfxMessageBox(_T("Database Error when Search :") + e->m_strError);
	}
	END_CATCH
		return result;
}

