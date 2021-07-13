#pragma once
#include "Room.h"
class RoomList
{
public:
	RoomList();
	virtual ~RoomList();
	void Clear();
	int GetLength() const;
	bool IsEmpty() const;
	bool IsRoomExist(int number);
	void GetRoom(int i, int& number, QString& type, int& price, bool& state) const;
	void Insert(const int& number, const QString& type, const int& price, const bool& state);
	void DeleteRoom(int i = -1);
	RoomList& operator=(const RoomList& list_);
private:
	Room* head_;
	int length_;
};