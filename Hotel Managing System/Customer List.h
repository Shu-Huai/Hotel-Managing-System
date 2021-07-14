#pragma once
#include "Customer.h"
class CustomerList
{
public:
	CustomerList();
	~CustomerList();
	void Clear();
	int GetLength() const;
	bool IsEmpty() const;
	bool IsCustomerExist(const QString& ID) const;
	void GetCustomer(int index, QString& name, QString& ID, int& roomNumber, int& day) const;
	QString GetCustomerName(int index) const;
	int GetCustomerRoomNumber(int index) const;
	int GetCustomerDay(int index) const;
	void InsertCustomer(const QString& name, const QString& ID, int roomNumber, int day);
	void DeleteCustomer(int index);
	CustomerList& operator=(const CustomerList& list_);
private:
	Customer* head_;
	int length_;
};