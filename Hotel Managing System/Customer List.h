#pragma once
#include "Customer.h"
class CustomerList
{
public:
	CustomerList();
	~CustomerList();
	void Clear();
	bool IsEmpty() const;
	bool IsCustomerExist(const QString& ID) const;
	void InsertCustomer(const QString& name, const QString& ID, int roomNumber, int day);
	void DeleteCustomer(int index);
	void SetCustomer(int index, const QString& name, const QString& ID, int roomNumber, int day);
	int GetLength() const;
	void GetCustomer(int index, QString& name, QString& ID, int& roomNumber, int& day) const;
	QString GetCustomerName(int index) const;
	QString GetCustomerID(int index) const;
	int GetCustomerRoomNumber(int index) const;
	int GetCustomerDay(int index) const;
	CustomerList& SearchCustomer(QString& name, QString& ID, int roomNumber, int day);
	CustomerList& operator=(const CustomerList& list);
private:
	Customer* head_;
	int length_;
};