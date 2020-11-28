#pragma once
#include "Room.h"
#include <iostream>
using namespace std;
struct Customer
{
	string ID;
	string Name;
	int InDate = 0;
	int OutDate = 0;
	string InRoomNumber;
	int Cost = 0;
	Customer* next = NULL;
};
int GetDays(int year, int month, int day);
int GetInDays(int year1, int month1, int day1, int year2, int month2, int day2);
void InsertCustomer(Room*& RoomList, Customer*& CustomerList);
void SearchCustomer(Customer*& CustomerList);
void ShowCustomer(Customer*& CustomerList);
void CheckOut(Room*& RoomList, Customer*& CutomerList);
void ChangeCustomer(Room*& RoomList, Customer*& CutomerList);