#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "Room.h"
#include "File.h"
#include "Customer.h"
using namespace std;
void Insert(Room*& RoomList, Customer*& CustomerList)
{
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "               1.录入客房信息" << endl
		<< endl
		<< "               2.录入客人信息" << endl
		<< endl
		<< "               3.返回上层菜单" << endl
		<< "请选择：";
	char ChooseFunction;
	cin >> ChooseFunction;
	system("cls");
	if (ChooseFunction >= '1' and ChooseFunction <= '3')
	{
		switch (ChooseFunction)
		{
		case '1':
			InsertRoom(RoomList);
			break;
		case '2':
			InsertCustomer(RoomList, CustomerList);
			break;
		case '3':;
		}
	}
	else
	{
		cout << endl
			<< endl
			<< "                客房管理系统" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< endl
			<< "                  非法字符。" << endl;
		system("pause");
		system("cls");
		Insert(RoomList, CustomerList);
	}
}
int main()
{
	system("color F0");
	Room* RoomList = NULL;
	Customer* CustomerList = NULL;
	ifstream filein("Customer.txt");
	if (!filein.is_open())
	{
		ofstream fileout("Customer.txt", ios::trunc);
		fileout.close();
	}
	ifstream filein2("Room.txt");
	if (!filein2.is_open())
	{
		ofstream fileout2("Room.txt", ios::trunc);
		fileout2.close();
	}
	system("cls");
	Read(RoomList, CustomerList);
	while (1)
	{
		cout << endl
			<< endl
			<< "                客房管理系统             " << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "               1.录入" << endl
			<< endl
			<< "               2.查询" << endl
			<< endl
			<< "               3.退房" << endl
			<< endl
			<< "               4.修改" << endl
			<< endl
			<< "               5.退出系统" << endl
			<< endl;
		cout << "请选择：";
		char ChooseFunction = 0;
		ChooseFunction = getchar();
		system("cls");
		switch (ChooseFunction)
		{
		case '1':
			Insert(RoomList, CustomerList);
			break;
		case '2':
			//searchdepend();
			break;
		case '3':
			//deletecustomer();
			break;
		case '4':
			//changedepend();
			break;
		case '5':
			Save(RoomList, CustomerList);
			exit(0);
		case '\n':
			continue;
			break;
		default:
			cout << endl
				<< endl
				<< "                客房管理系统" << endl
				<< endl
				<< "      ----------------------------------" << endl
				<< endl
				<< endl
				<< "                  非法字符。" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}