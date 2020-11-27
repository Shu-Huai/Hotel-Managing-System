#include "Customer.h"
int GetDays(int year, int month, int day)
{
	int m[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		m[2]++;
	}
	int result = 0;
	for (int i = 1; i < year; i++)
	{
		result += 365;
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
		{
			result++;
		}
	}
	for (int i = 1; i < month; i++)
	{
		result += m[i];
	}
	result += day;
	return result;
}
int GetInDays(int year1, int month1, int day1, int year2, int month2, int day2)
{
	return abs(GetDays(year2, month2, day2) - GetDays(year1, month1, day1));
}
void InsertCustomer(Room*& RoomList, Customer*& CustomerList)
{
	Customer* TempCustomer = new Customer;
	cout << "\n\n                客房管理系统             \n\n";
	cout << "      ----------------------------------   \n\n";
	cout << "请输入需入住的客人的身份信息（身份证号）：";
	cin >> TempCustomer->ID;
	Customer* p = CustomerList;
	while (p != NULL)
	{
		if (p->ID == TempCustomer->ID)
		{
			system("cls");
			cout << "\n\n                客房管理系统             \n\n";
			cout << "      ----------------------------------   \n\n";
			cout << "该客人已存在，如需修改请输入Y,回到主菜单请输入任意字母：";
			char input;
			input = getchar();
			if (input == 'Y' or input == 'y')
			{
				InsertCustomer(RoomList, CustomerList);
			}
			return;
		}
		p = p->next;
	}
	cout << "请输入需入住的客人的姓名：";
	cin >> TempCustomer->Name;
	cout << "请输入需入住该客人入住日期：";
	cin >> TempCustomer->InDate;
	cout << "请输入需入住该客人退房日期：";
	cin >> TempCustomer->OutDate;
	int InYear, InMonth, InDay, OutYear, OutMonth, OutDay;
	InYear = TempCustomer->InDate / 10000;
	InMonth = TempCustomer->InDate / 100 % 100;
	InDay = TempCustomer->InDate % 100;
	OutYear = TempCustomer->OutDate / 10000;
	OutMonth = TempCustomer->OutDate / 100 % 100;
	OutDay = TempCustomer->OutDate % 100;
	int i = 0, judge = 0;
	Room* q = RoomList;
	system("cls");
	cout << "\n\n                客房管理系统             \n\n";
	cout << "      ----------------------------------   \n\n";
	if (q == NULL)
	{
		cout << "              请先录入客房信息。";
		system("pause");
		return;
	}
ShowRoom:
	while (q != NULL) //选择房间
	{
		if (q->State != 1 and q->Price != 0)
		{
			cout << endl;
			cout << "房间编号：" << q->Number << "  ";
			cout << "房间类型：" << q->Type << "  ";
			cout << "房间单价：" << q->Price << "  ";
			i = 1;
		}
		q = q->next;
	}
	if (q == NULL and i == 0)
	{
		cout << "   暂无空房间";
		system("pause");
		return;
	}
	cout << endl;
	cout << "  请选择房间（输入房间号）：" << endl;
	string number;
	cin >> number;
	q = RoomList;
	while (q != NULL) //更新房间与客人信息
	{
		if (number == q->Number)
		{
			judge = 1;
			q->State = 1;
			TempCustomer->InRoomNumber = number;
			TempCustomer->Cost = q->Price * GetInDays(InYear, InMonth, InDay, OutYear, OutMonth, OutDay);
			break;
		}
		q = q->next;
	}
	system("cls");
	if (judge == 1)
	{
		cout << "\n\n                客房管理系统             \n\n";
		cout << "      ----------------------------------   \n\n";
		cout << "                已更新客房与客人信息。\n";
		system("pause");
		system("cls");
		TempCustomer->next = CustomerList;
		CustomerList = TempCustomer;
	}
	else
	{
		cout << "\n\n                客房管理系统             \n\n";
		cout << "      ----------------------------------   \n\n";
		cout << "             房间编号输入错误，请重新输入。\n";
		cout << endl;
		goto ShowRoom;
	}
}