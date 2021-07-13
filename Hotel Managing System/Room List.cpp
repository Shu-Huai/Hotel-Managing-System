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
bool RoomList::IsRoomExist(int number)
{
	Room* p = head_;
	while (p)
	{
		if (number == p->number_)
		{
			return 1;
		}
		p = p->next_;
	}
	return 0;
}
void RoomList::GetRoom(int i, int& number, QString& type, int& price, bool& state) const
{
	if (i < 1 || i > length_)
	{
		throw std::string("·¶Î§´íÎó¡£");
	}
	Room* p = head_;
	for (int j = 0; j < i; j++)
	{
		p = p->next_;
	}
	number = p->number_;
	type = p->type_;
	price = p->price_;
	state = p->isFull_;
}
void RoomList::Insert(const int& number, const QString& type, const int& price, const bool& state)
{
	Room* p = head_;
	while (p->next_)
	{
		p = p->next_;
	}
	Room* q = new Room;
	*q = Room(number, type, price, state, NULL);
	p->next_ = q;
	length_++;
}
void RoomList::DeleteRoom(int i)
{
	if (i == -1)
	{
		i = length_;
	}
	if (i < 1 || i > length_)
	{
		throw std::string("·¶Î§´íÎó¡£");
	}
	Room* p = head_;
	for (int j = 0; j < i - 1; j++)
	{
		p = p->next_;
	}
	Room* q = p->next_;
	p->next_ = p->next_->next_;
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
			bool state = 0;
			list_.GetRoom(i + 1, number, type, price, state);
			Insert(number, type, price, state);
		}
	}
	return *this;
}