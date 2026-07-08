#include "pch.h"
#include "Book.h"

Book::Book() :m_id(0), m_name(L""), m_price(0.0), m_quantity(0), m_createdDate(L"") {}

Book::Book(int id,const CString& name, double price, int quantity,const  CString& createdDate)
    : m_id(id), m_name(name), m_price(price), m_quantity(quantity), m_createdDate(createdDate)
{}
