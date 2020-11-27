#include <iostream>
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
	switch (ChooseFunction)
	{
	case '1':
		InsertRoom(RoomList);
		break;
	case '2':
		InsertCustomer(RoomList, CustomerList);
		break;
	case '3':
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
		Insert(RoomList, CustomerList);
		return;
	}
}
void Search(Room*& RoomList, Customer*& CustomerList)
{
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "               1.按类型查询客房信息" << endl
		<< endl
		<< "               2.按价格查询客房信息" << endl
		<< endl
		<< "               3.查询客人信息" << endl
		<< endl
		<< "               4.查询所有客人信息" << endl
		<< endl
		<< "               5.返回上层菜单" << endl
		<< endl
		<< "  请选择：";
	char ChooseFunction;
	cin >> ChooseFunction;
	system("cls");
	switch (ChooseFunction)
	{
	case '1':
		SearchByType(RoomList);
		break;
	case '2':
		SearchByPrice(RoomList);
		break;
	case '3':
		//searchcustomer();
		break;
	case '4':
		//searchall();
		break;
	case '5':
		break;
	default:
		cout << endl
			<< endl
			<< "                客房管理系统" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "                  非法字符。" << endl;
		system("pause");
		system("cls");
	}
}
int main()
{
	system("color F0");
	Room* RoomList = NULL;
	Customer* CustomerList = NULL;
	ifstream RoomFile("Room.txt");
	ifstream CustomerFile("Customer.txt");
	if (!RoomFile.is_open())
	{
		ofstream fileout2("Room.txt", ios::trunc);
	}
	if (!CustomerFile.is_open())
	{
		ofstream fileout("Customer.txt", ios::trunc);
	}
	RoomFile.close();
	CustomerFile.close();
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
			Search(RoomList, CustomerList);
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
		}
	}
	return 0;
}