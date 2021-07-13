#pragma once
#include "Room.h"
class RoomList
{
public:
	RoomList();
	~RoomList();
	void Clear();
	int GetLength() const;
	bool IsEmpty() const;
	bool IsRoomExist(int number) const;
	void GetRoom(int index, int& number, QString& type, int& price, bool& isFull) const;
	void Insert(const int& number, const QString& type, const int& price, const bool& isFull);
	void DeleteRoom(int index);
	RoomList& operator=(const RoomList& list_);
private:
	Room* head_;
	int length_;
};