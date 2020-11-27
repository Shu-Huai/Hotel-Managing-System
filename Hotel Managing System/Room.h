#pragma once
#include <iostream>
using namespace std;
struct Room
{
	string Number;
	string Type;
	int Price = 0;
	bool State = 0;
	Room* next = NULL;
};
void InsertRoom(Room*& RoomList);