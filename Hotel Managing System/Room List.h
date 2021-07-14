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
	int GetRoomPriceByNumber(int number) const;
	int GetRoomNumber(int index) const;
	QString GetRoomType(int index) const;
	int GetRoomPrice(int index) const;
	bool GetRoomState(int index) const;
	RoomList& SearchRoom(int number, const QString& type, int price, int isFull);
	RoomList& operator=(const RoomList& list_);
private:
	Room* head_;
	int length_;
};