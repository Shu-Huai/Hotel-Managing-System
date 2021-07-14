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
void RoomList::InsertRoom(int number, const QString& type, int price, bool isFull)
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
	for (int i = 0; i < index; i++)
	{
		p = p->next_;
	}
	Room* q = p->next_;
	p->next_ = q->next_;
	delete q;
	length_--;
}
void RoomList::SetFull(int number)
{
	Room* p = head_->next_;
	while (p && p->number_ != number)
	{
		p = p->next_;
	}
	if (!p)
	{
		throw std::string("房间不存在。");
	}
	p->isFull_ = true;
}
void RoomList::SetRoom(int index, int number, const QString& type, int price, bool isFull)
{
	if (index < 0 || index >= length_)
	{
		throw std::string("范围错误。");
	}
	Room* p = head_->next_;
	for (int i = 0; i < index; i++)
	{
		p = p->next_;
	}
	p->number_ = number;
	p->type_ = type;
	p->price_ = price;
	p->isFull_ = isFull;
}
void RoomList::CheckOut(int number)
{
	Room* p = head_->next_;
	while (p && p->number_ != number)
	{
		p = p->next_;
	}
	if (!p)
	{
		throw std::string("房间不存在。");
	}
	p->isFull_ = false;
}
int RoomList::GetLength() const
{
	return length_;
}
int RoomList::GetIndex(int number) const
{
	Room* p = head_->next_;
	int index = 0;
	while (p && p->number_ != number)
	{
		index++;
		p = p->next_;
	}
	if (!p)
	{
		throw std::string("房间不存在。");
	}
	return index;
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
int RoomList::GetRoomPriceByNumber(int number) const
{
	Room* p = head_->next_;
	while (p && p->number_ != number)
	{
		p = p->next_;
	}
	if (!p)
	{
		throw std::string("房间不存在。");
	}
	return p->price_;
}
int RoomList::GetRoomNumber(int index) const
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
	return p->number_;
}
QString RoomList::GetRoomType(int index) const
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
	return p->type_;
}
int RoomList::GetRoomPrice(int index) const
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
	return p->price_;
}
bool RoomList::GetRoomState(int index) const
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
	return p->isFull_;
}
RoomList& RoomList::SearchRoom(int number, const QString& type, int price, int isFull)
{
	RoomList* list = new RoomList;
	Room* p = head_->next_;
	while (p)
	{
		QString tempNumber = QString("%1").arg(number == -1 ? p->number_ : number);
		QString tempType = type == "" ? p->type_ : type;
		QString tempPrice = QString("%1").arg(price == -1 ? p->price_ : price);
		QString tempState = QString("%1").arg(isFull == -1 ? p->isFull_ : isFull);
		if (QString("%1").arg(p->number_).startsWith(tempNumber) && p->type_.startsWith(tempType) &&
			QString("%1").arg(p->price_).startsWith(tempPrice) && QString("%1").arg(p->isFull_).startsWith(tempState))
		{
			list->InsertRoom(p->number_, p->type_, p->price_, p->isFull_);
		}
		p = p->next_;
	}
	return *list;
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
			InsertRoom(number, type, price, isFull);
		}
	}
	return *this;
}