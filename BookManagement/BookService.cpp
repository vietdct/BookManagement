#include "pch.h"
#include "BookService.h"

BookService::BookService() 
{
};

//Validate for Update/Add..
bool BookService::ValidateInput(const CString& name, double price, int quantity, CString& outErrorMsg)
{
	//Rule 1 : Book_Name cant be left blank
	CString trimmedName = name;
	trimmedName.Trim();
	if(trimmedName.IsEmpty())
	{
		outErrorMsg = L"Book Name cannot be left blank. ";
		return false;
	}
	// Rule 2: price > 0 
	if (price < 0.0)
	{
		outErrorMsg = L"Price must be greater than 0.";
		return false;
	}
	if (quantity < 0)
	{
		outErrorMsg = L"Quantity cannot be negative.";
		return false;
	}
	return true;
}

// GetAllBook
std::vector<Book> BookService::GetAllBooks() {
	return m_repository.GetAllBooks();
}

//Add 
bool BookService::AddBook(const CString& name, double price, int quantity, CString& outErrorMsg)
{
	if (!ValidateInput(name, price, quantity, outErrorMsg)) 
	{
		return false; // dung , k goi repository neu validate
	}
	Book newBook(0, name, price, quantity, L""); //id = 0 tu sinh IDENTITY
	if (!m_repository.InsertBook(newBook))
	{
		outErrorMsg = L"Can't to add the book to the database.";
		return false;
	}
	return true;
}

// Update
bool BookService::UpdateBook(int id, const CString& name, double price, int quantity, CString& outErrorMsg)
{
	if (!ValidateInput(name, price, quantity, outErrorMsg))
	{
		return false;
	}
	Book book(id, name, price, quantity, L"");
	if (!m_repository.UpdateBook(book))
	{
		outErrorMsg = L"Can't update book . Check id again!.";
		return false;
	}
	return true;
}

//Delete
bool BookService::DeleteBook(int id, CString& outErrorMsg)
{
	if (!m_repository.DeleteBook(id))
	{
		outErrorMsg = L"Can't Delete book. Please check id again.";
		return false;
	}
	return true;
}

//Search
std::vector<Book> BookService::SearchBook(const CString& keyword)
{
	return m_repository.SearchBookByName(keyword);
}



