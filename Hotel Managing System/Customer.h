#pragma once
#include <QString>
class Customer
{
public:
	friend class CustomerList;
	Customer(QString name = "", QString ID = "", int roomNumber = 0, int day = 0, Customer* next = NULL);
private:
	QString name_;
	QString ID_;
	int roomNumber_;
	int day_;
	Customer* next_;
};