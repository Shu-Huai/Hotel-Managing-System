#include "Room.h"
void InsertRoom(Room*& RoomList)
{
	cout << endl
		<< endl
		<< "                �ͷ�����ϵͳ" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< endl
		<< "��������¼��ķ����ţ�";
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
				<< "                �ͷ�����ϵͳ" << endl
				<< endl
				<< "      ----------------------------------" << endl
				<< endl
				<< endl
				<< "                �÷����Ѵ��ڡ�" << endl;
			system("pause");
			goto Continue;
		}
		p = p->next;
	}
	cout << "����������ס�ķ������ͣ�";
	cin >> TempRoom->Type;
	cout << "������÷��䵥�ۣ���λRMB����������������֣���";
	cin >> TempRoom->Price;
	TempRoom->State = 0;
	TempRoom->next = RoomList;
	RoomList = TempRoom;
	system("cls");
	cout << endl
		<< endl
		<< "                �ͷ�����ϵͳ" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< endl
		<< "                  ¼��ɹ���" << endl;
	system("pause");
	system("cls");
Continue:
	char temp = getchar();
	system("cls");
	cout << endl
		<< endl
		<< "                �ͷ�����ϵͳ" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< endl
		<< "         �Ƿ���Ҫ����¼�뷿�䣿��Y/N��" << endl;
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
		<< "                �ͷ�����ϵͳ" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< endl << "    ����������ҵķ������ͣ�";
	string input;
	cin >> input;
	bool judge = 0;
	Room* p = RoomList;
	while (p != NULL)
	{
		if (input == p->Type)
		{
			cout << endl
				<< "������" << p->Number << "    "
				<< "��������" << p->Type << "    "
				<< "���䵥��" << p->Price << "    ";
			if (p->State == 0)
			{
				cout << "�÷������ˡ�" << endl;
			}
			else
			{
				cout << "�÷������п�����ס��" << endl;
			}
			judge = 1;
		}
		p = p->next;
	}
	if (judge == 0)
	{
		system("cls");
		cout << "\n\n                �ͷ�����ϵͳ             \n\n";
		cout << "      ----------------------------------   \n\n";
		cout << "		 ���޴��෿�䷿" << endl;
	}
	system("pause");
	system("cls");
}
void SearchByPrice(Room*& RoomList)
{
	cout << endl
		<< endl
		<< "                �ͷ�����ϵͳ" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< endl << "����������ҵķ������¼۸�����(���� ����)��";
	int min, max;
	cin >> min >> max;
	Room* p = RoomList;
	while (p != NULL)
	{
		if (p->Price >= min and p->Price <= max)
		{
			cout << endl
				<< "������" << p->Number << "    "
				<< "��������" << p->Type << "    "
				<< "���䵥��" << p->Price << "    ";
			if (p->State == 0)
			{
				cout << "�÷������ˡ�" << endl;
			}
			else
			{
				cout << "�÷������п�����ס��" << endl;
			}
		}
		p = p->next;
	}
	system("pause");
	system("cls");
}