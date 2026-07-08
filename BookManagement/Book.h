#pragma once
#include "afx.h"
class Book
{
public:
	Book();
	Book(int id,const CString& name, double price, int quantity, const CString& createdDate);

	//------------------ Getter ----------------------
	int GetId() const { return m_id; };
	CString GetName() const { return m_name; };
	double GetPrice() const { return m_price; };
	int GetQuantity() const { return m_quantity; };
	CString GetCreatedDate() const { return m_createdDate; };

	//------------------ Setter ----------------------
	void SetId(int id) { m_id = id; };
	void SetName(CString name) { m_name = name; };
	void SetPrice(double price) { m_price = price; };
	void SetQuantity(int quantity) { m_quantity = quantity; };
	void SetCreatedDate(CString createdDate) { m_createdDate = createdDate; };

private:
	int m_id;
	CString m_name;
	double m_price;
	int m_quantity;
	CString m_createdDate;
};

