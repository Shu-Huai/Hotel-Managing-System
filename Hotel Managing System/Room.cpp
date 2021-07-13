﻿#include "Room.h"
void InsertRoom(Room*& RoomList)
{
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< endl
		<< "请输入需录入的房间编号：";
	Room* TempRoom = new Room;
	cin >> TempRoom->Number;
	Room* p = RoomList;
	while (p != NULL)
	{
		if (TempRoom->Number == p->Number)
		{
			system("cls");
			cout << endl
				<< endl
				<< "                客房管理系统" << endl
				<< endl
				<< "      ----------------------------------" << endl
				<< endl
				<< endl
				<< "                该房间已存在。" << endl;
			system("pause");
			goto Continue;
		}
		p = p->next;
	}
	cout << "请输入需入住的房间类型：";
	cin >> TempRoom->Type;
	cout << "请输入该房间单价（单位RMB）（请务必输入数字）：";
	cin >> TempRoom->Price;
	TempRoom->State = 0;
	TempRoom->next = RoomList;
	RoomList = TempRoom;
	system("cls");
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< endl
		<< "                  录入成功。" << endl;
	system("pause");
	system("cls");
Continue:
	char temp = getchar();
	system("cls");
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< endl
		<< "         是否需要继续录入房间？（Y/N）" << endl;
	char input;
	input = getchar();
	system("cls");
	if (input == 'Y' or input == 'y')
	{
		InsertRoom(RoomList);
		return;
	}
	system("cls");
}
void SearchByType(Room*& RoomList)
{
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "    请输入需查找的房间类型：";
	string input;
	cin >> input;
	bool judge = 0;
	Room* p = RoomList;
	while (p != NULL)
	{
		if (input == p->Type)
		{
			cout << endl
				<< "房间编号" << p->Number << "    "
				<< "房间类型" << p->Type << "    "
				<< "房间单价" << p->Price << "    ";
			if (p->State == 0)
			{
				cout << "该房间无人。" << endl;
			}
			else
			{
				cout << "该房间已有客人入住。" << endl;
			}
			judge = 1;
		}
		p = p->next;
	}
	if (judge == 0)
	{
		system("cls");
		cout << "\n\n                客房管理系统             \n\n";
		cout << "      ----------------------------------   \n\n";
		cout << "		 查无此类房间房" << endl;
	}
	system("pause");
	system("cls");
}
void SearchByPrice(Room*& RoomList)
{
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "请输入需查找的房间上下价格区间(下限 上限)：";
	int min, max;
	cin >> min >> max;
	Room* p = RoomList;
	while (p != NULL)
	{
		if (p->Price >= min and p->Price <= max)
		{
			cout << endl
				<< "房间编号" << p->Number << "    "
				<< "房间类型" << p->Type << "    "
				<< "房间单价" << p->Price << "    ";
			if (p->State == 0)
			{
				cout << "该房间无人。" << endl;
			}
			else
			{
				cout << "该房间已有客人入住。" << endl;
			}
		}
		p = p->next;
	}
	system("pause");
	system("cls");
}
void ChangeRoom(Room*& RoomList)
{
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "         请输入需修改的客房的房号：";
	string input;
	cin >> input;
	bool judge = 0;
	Room* p = RoomList;
	while (p != NULL)
	{
		if (input == p->Number)
		{
			cout << endl;
			if (p->State == 0)
			{
				cout << "  请输入需修改的客房的类型：";
				cin >> p->Type;
				cout << "  请输入需修改的客房的单价：";
				cin >> p->Price;
			}
			else cout << "该房间已有客人入住,请等客人退房后修改客房信息" << endl;
			judge = 1;
		}
		p = p->next;
	}
	if (judge == 0)
	{
		system("cls");
		cout << endl
			<< endl
			<< "                客房管理系统" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "		          查无此房。" << endl;
	}
	system("pause");
	system("cls");
}