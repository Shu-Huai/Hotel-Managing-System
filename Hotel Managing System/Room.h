#pragma once
#include <QString>
class Room
{
	friend class RoomList;
public:
	Room(int number = 0, QString type = "", int price = 0, bool isFull = false, Room* next = NULL);
private:
	int number_;
	QString type_;
	int price_;
	bool isFull_;
	Room* next_;
};