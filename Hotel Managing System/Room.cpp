#include "Room.h"
void InsertRoom(Room*& RoomList)
{
	Room* TempRoom = new Room;
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< endl
		<< "请输入需录入的房间编号：";
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