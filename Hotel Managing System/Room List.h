#pragma once
#include "Room.h"
class RoomList
{
public:
	RoomList();
	~RoomList();
	void Clear();
	bool IsEmpty() const;
	bool IsRoomExist(int number) const;
	void InsertRoom(int number, const QString& type, int price, bool isFull);
	void DeleteRoom(int index);
	void SetFull(int number);
	void SetRoom(int index, int number, const QString& type, int price, bool isFull);
	void CheckOut(int number);
	int GetLength() const;
	int GetIndex(int number) const;
	void GetRoom(int index, int& number, QString& type, int& price, bool& isFull) const;
	int GetRoomPrice(int number) const;
	RoomList& operator=(const RoomList& list_);
private:
	Room* head_;
	int length_;
};