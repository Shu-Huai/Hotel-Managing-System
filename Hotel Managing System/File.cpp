#include "File.h"
#include <fstream>
using namespace std;
void Read(Room*& RoomList, Customer*& CustomerList)
{
	ifstream RoomFile("Room.txt");
	while (!RoomFile.eof())
	{
		Room* p = new Room;
		RoomFile >> p->Number >> p->Type >> p->Price >> p->State;
		if (p->Number != "" and p->Type != "" and p->Price != 0)
		{
			p->next = RoomList;
			RoomList = p;
		}
	}
	RoomFile.close();
	ifstream CustomerFile("Customer.txt");
	while (!CustomerFile.eof())
	{
		Customer* p = new Customer;
		CustomerFile >> p->ID >> p->Name >> p->InDate >> p->OutDate >> p->InRoomNumber >> p->Cost;
		if (p->ID != "" and p->Name != "" and p->InDate != 0 and p->OutDate != 0)
		{
			p->next = CustomerList;
			CustomerList = p;
		}
	}
	CustomerFile.close();
}
void Save(Room*& RoomList, Customer*& CustomerList)
{
	Room* p = RoomList;
	Customer* q = CustomerList;
	ofstream RoomFile("Room.txt", ios::trunc);
	while (p != NULL)
	{
		if (p->Number.length() == 0 or p->Type.length() == 0 or p->Price == 0)
		{
			continue;
		}
		RoomFile << p->Number << " " << p->Type << " " << p->Price << " " << p->State << endl;
		p = p->next;
	}
	RoomFile.close();
	ofstream CustomerFile("Customer.txt", ios::trunc);
	while (q != NULL)
	{
		if (q->ID == "" or q->Name == "" or q->InDate == 0 or q->OutDate == 0)
		{
			continue;
		}
		CustomerFile << q->ID << " ";
		CustomerFile << q->Name << " ";
		CustomerFile << q->InDate << " ";
		CustomerFile << q->OutDate << " " << q->InRoomNumber << " " << q->Cost << endl;
		q = q->next;
	}
	CustomerFile.close();
}