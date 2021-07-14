#include "Customer List.h"
#include <iostream>
CustomerList::CustomerList() : length_(0)
{
	head_ = new Customer;
	assert(head_);
}
CustomerList::~CustomerList()
{
	Clear();
	delete head_;
}
void CustomerList::Clear()
{
	Customer* p = head_->next_;
	while (p)
	{
		head_->next_ = p->next_;
		delete p;
		p = head_->next_;
	}
	length_ = 0;
}
bool CustomerList::IsEmpty() const
{
	return head_->next_ == NULL;
}
bool CustomerList::IsCustomerExist(const QString& ID) const
{
	Customer* p = head_;
	while (p)
	{
		if (ID == p->ID_)
		{
			return true;
		}
		p = p->next_;
	}
	return false;
}
void CustomerList::InsertCustomer(const QString& name, const QString& ID, int roomNumber, int day)
{
	Customer* p = head_;
	while (p->next_ && p->next_->ID_ <= ID)
	{
		p = p->next_;
	}
	Customer* q = new Customer(name, ID, roomNumber, day, p->next_);
	p->next_ = q;
	length_++;
}
void CustomerList::DeleteCustomer(int index)
{
	if (index < 0 || index >= length_)
	{
		throw std::string("范围错误。");
	}
	Customer* p = head_;
	for (int j = 0; j < index; j++)
	{
		p = p->next_;
	}
	Customer* q = p->next_;
	p->next_ = q->next_;
	delete q;
	length_--;
}
void CustomerList::SetCustomer(int index, const QString& name, const QString& ID, int roomNumber, int day)
{
	if (index < 0 || index >= length_)
	{
		throw std::string("范围错误。");
	}
	Customer* p = head_->next_;
	for (int i = 0; i < index; i++)
	{
		p = p->next_;
	}
	p->name_ = name;
	p->ID_ = ID;
	p->roomNumber_ = roomNumber;
	p->day_ = day;
}
int CustomerList::GetLength() const
{
	return length_;
}
void CustomerList::GetCustomer(int index, QString& name, QString& ID, int& roomNumber, int& day) const
{
	if (index < 0 || index >= length_)
	{
		throw std::string("范围错误。");
	}
	Customer* p = head_->next_;
	for (int i = 0; i < index; i++)
	{
		p = p->next_;
	}
	name = p->name_;
	ID = p->ID_;
	roomNumber = p->roomNumber_;
	day = p->day_;
}
QString CustomerList::GetCustomerName(int index) const
{
	if (index < 0 || index >= length_)
	{
		throw std::string("范围错误。");
	}
	Customer* p = head_->next_;
	for (int i = 0; i < index; i++)
	{
		p = p->next_;
	}
	return p->name_;
}
int CustomerList::GetCustomerRoomNumber(int index) const
{
	if (index < 0 || index >= length_)
	{
		throw std::string("范围错误。");
	}
	Customer* p = head_->next_;
	for (int i = 0; i < index; i++)
	{
		p = p->next_;
	}
	return p->roomNumber_;
}
int CustomerList::GetCustomerDay(int index) const
{
	if (index < 0 || index >= length_)
	{
		throw std::string("范围错误。");
	}
	Customer* p = head_->next_;
	for (int i = 0; i < index; i++)
	{
		p = p->next_;
	}
	return p->day_;
}
CustomerList& CustomerList::operator=(const CustomerList& list_)
{
	if (&list_ != this)
	{
		int length = list_.GetLength();
		Clear();
		for (int i = 0; i < length; i++)
		{
			QString name = "";
			QString ID = "";
			int roomNumber = 0;
			int day = 0;
			list_.GetCustomer(i, name, ID, roomNumber, day);
			InsertCustomer(name, ID, roomNumber, day);
		}
	}
	return *this;
}