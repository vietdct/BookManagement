#pragma once
#include "Book.h"
#include "BookRepository.h"

//Service chi chua bussiness rule/validate
class BookService
{
public:
	BookService();
	std::vector<Book> GetAllBooks();

	bool AddBook(const CString& name, double price, int quantity, CString& outErrorMsg);
	bool UpdateBook(int id, const CString& name, double price, int quantity, CString& outErrorMsg);
	bool DeleteBook(int id, CString& outErrorMsg);
	std::vector<Book> SearchBook(const CString& keyword);

private:
	BookRepository m_repository;
	bool ValidateInput(const CString& name, double price, int quantity, CString& outErrorMsg);
};

