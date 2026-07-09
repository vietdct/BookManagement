#pragma once
#include <afxdb.h>
#include <vector>
#include "Book.h"

class BookRepository
{
public:
	BookRepository();
	std::vector<Book> GetAllBooks();
	bool InsertBook( Book& book);
	bool UpdateBook(const Book& book);
	bool DeleteBook(int id);
	std::vector<Book> SearchBookByName(const CString& nameBook);
};

