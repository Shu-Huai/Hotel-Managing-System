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
	void GetCustomer(int index, QString& name, QString& ID, int& roomNumber) const;
	int GetCustomerRoomNumber(int index) const;
	void Insert(const QString& name, const QString& ID, int roomNumber);
	void DeleteCustomer(int index);
	CustomerList& operator=(const CustomerList& list_);
private:
	Customer* head_;
	int length_;
};