#include "Room List.h"
#include <iostream>
RoomList::RoomList() : length_(0)
{
	head_ = new Room;
	assert(head_);
}
RoomList::~RoomList()
{
	Clear();
	delete head_;
}
void RoomList::Clear()
{
	Room* p = head_->next_;
	while (p)
	{
		head_->next_ = p->next_;
		delete p;
		p = head_->next_;
	}
	length_ = 0;
}
int RoomList::GetLength() const
{
	return length_;
}
bool RoomList::IsEmpty() const
{
	return head_->next_ == NULL;
}
bool RoomList::IsRoomExist(int number) const
{
	Room* p = head_;
	while (p)
	{
		if (number == p->number_)
		{
			return true;
		}
		p = p->next_;
	}
	return false;
}
void RoomList::GetRoom(int index, int& number, QString& type, int& price, bool& isFull) const
{
	if (index < 0 || index >= length_)
	{
		throw std::string("范围错误。");
	}
	Room* p = head_->next_;
	for (int j = 0; j < index; j++)
	{
		p = p->next_;
	}
	number = p->number_;
	type = p->type_;
	price = p->price_;
	isFull = p->isFull_;
}
void RoomList::Insert(const int& number, const QString& type, const int& price, const bool& isFull)
{
	Room* p = head_;
	while (p->next_ && p->next_->number_ <= number)
	{
		p = p->next_;
	}
	Room* q = new Room(number, type, price, isFull, p->next_);
	p->next_ = q;
	length_++;
}
void RoomList::DeleteRoom(int index)
{
	if (index < 0 || index >= length_)
	{
		throw std::string("范围错误。");
	}
	Room* p = head_;
	for (int j = 0; j < index; j++)
	{
		p = p->next_;
	}
	Room* q = p->next_;
	p->next_ = q->next_;
	delete q;
	length_--;
}
RoomList& RoomList::operator=(const RoomList& list_)
{
	if (&list_ != this)
	{
		int length = list_.GetLength();
		Clear();
		for (int i = 0; i < length; i++)
		{
			int number = 0;
			QString type = "";
			int price = 0;
			bool isFull = 0;
			list_.GetRoom(i, number, type, price, isFull);
			Insert(number, type, price, isFull);
		}
	}
	return *this;
}