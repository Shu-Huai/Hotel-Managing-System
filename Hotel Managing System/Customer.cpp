#include "Customer.h"
using namespace std;
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
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "请输入需入住的客人的身份信息（身份证号）：";
	cin >> TempCustomer->ID;
	Customer* p = CustomerList;
	while (p != NULL)
	{
		if (p->ID == TempCustomer->ID)
		{
			system("cls");
			cout << endl
				<< endl
				<< "                客房管理系统" << endl
				<< endl
				<< "      ----------------------------------" << endl
				<< endl
				<< "该客人已存在，如需修改请输入Y,回到主菜单请输入任意字母：";
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
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl;
	if (q == NULL)
	{
		cout << "              请先录入客房信息。";
		system("pause");
		return;
	}
ShowRoom:
	while (q != NULL)
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
		cout << "   暂无空房间。";
		system("pause");
		return;
	}
	cout << endl
		<< "  请选择房间（输入房间号）：" << endl;
	string number;
	cin >> number;
	q = RoomList;
	while (q != NULL)
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
		cout << endl
			<< endl
			<< "                客房管理系统" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "            已更新客房与客人信息。" << endl;
		system("pause");
		system("cls");
		TempCustomer->next = CustomerList;
		CustomerList = TempCustomer;
	}
	else
	{
		cout << endl
			<< endl
			<< "                客房管理系统" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "        房间编号输入错误，请重新输入。" << endl
			<< endl;
		goto ShowRoom;
	}
}
void SearchCustomer(Customer*& CustomerList)
{
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "      请输入需查找的客人姓名或身份证：";
	string input;
	cin >> input;
	bool judge = 0;
	Customer* p = CustomerList;
	while (p != NULL)
	{
		if (input == p->Name or input == p->ID)
		{
			cout << endl
				<< "客人姓名" << p->Name << endl
				<< endl
				<< "客人身份证号" << p->ID << endl
				<< endl
				<< "客人入住时间" << p->InDate << endl
				<< endl
				<< "客人退房时间" << p->OutDate << endl
				<< endl
				<< "客人入住房号" << p->InRoomNumber << endl
				<< endl
				<< "客人消费金额" << p->Cost << endl
				<< endl;
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
			<< "		          查无此人。" << endl;
	}
	system("pause");
	system("cls");
}
void ShowCustomer(Customer*& CustomerList)
{
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl;
	bool judge = 0;
	Customer* p = CustomerList;
	while (p != NULL)
	{
		cout << "客人姓名" << p->Name << "    "
			<< "客人身份证号" << p->ID << "   "
			<< "客人入住时间" << p->InDate << "   "
			<< "客人退房时间" << p->OutDate << "  "
			<< "客人入住房号" << p->InRoomNumber << "  "
			<< "客人消费金额" << p->Cost << endl
			<< endl;
		judge = 1;
		p = p->next;
	}
	if (judge == 0)
		cout << "             暂无客人信息。" << endl
		<< endl;
	system("pause");
	system("cls");
}
void CheckOut(Room*& RoomList, Customer*& CustomerList)
{
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "       请输入退房客人身份证号或姓名：";
	string input;
	cin >> input;
	int pay = 0;
	bool judge = 0;
	Room* p = RoomList;
	Customer* q = CustomerList;
	Customer* qfront = CustomerList;
	while (q != NULL and input != q->Name and input != q->ID)
	{
		qfront = q;
		q = q->next;
	}
	q = CustomerList;
	while (q != NULL)
	{
		if (input == q->Name or input == q->ID)
		{
			while (p != NULL)
			{
				if (p->Number == q->InRoomNumber)
				{
					p->State = 0;
					break;
				}
				p = p->next;
			}
			pay = q->Cost;
			judge = 1;
			break;
		}
		q = q->next;
	}
	if (q == NULL)
	{
	}
	else
	{
		if (q == CustomerList)
		{
			CustomerList = CustomerList->next;
		}
		else
		{
			qfront->next = q->next;
		}
	}
	delete q;
	system("cls");
	if (judge == 1)
	{
		cout << endl
			<< endl
			<< "                客房管理系统" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "       客人退房成功，需支付: " << pay << endl;
	}
	else
	{
		cout << endl
			<< endl
			<< "                客房管理系统" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "                该客人不存在。" << endl;
	}
	system("pause");
	system("cls");
}
void ChangeCustomer(Room*& RoomList, Customer*& CutomerList)
{
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "  请输入需修改的客人的身份信息（身份证号）：";
	string input;
	cin >> input;
	system("cls");
	cout << endl
		<< endl
		<< "                客房管理系统" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl;
	Customer* p = CutomerList;
	int yy3, mm3, dd3;
	while (p != NULL)
	{
		if (input == p->ID)
		{
			yy3 = p->OutDate / 10000;
			mm3 = p->OutDate / 100 % 100;
			dd3 = p->OutDate % 100;
			string inroomnumber = p->InRoomNumber;
			cout << "  请输入需修改的客人的姓名：";
			cin >> p->Name;
			cout << "  请输入需修改该客人入住日期：";
			cin >> p->InDate;
			cout << "  请输入需修改该客人退房日期：";
			cin >> p->OutDate;
			cout << "  是否需要更换房间（Y/N）：";
			char ChooseFunction;
			cin >> ChooseFunction;
			if (ChooseFunction == 'Y' or ChooseFunction == 'y')
			{
				int InYear, InMonth, InDay, OutYear, OutMonth, OutDay;
				InYear = p->InDate / 10000;
				InMonth = p->InDate / 100 % 100;
				InDay = p->InDate % 100;
				OutYear = p->OutDate / 10000;
				OutMonth = p->OutDate / 100 % 100;
				OutDay = p->OutDate % 100;
				Room* q = RoomList;
			ShowRoom:
				system("cls");
				cout << endl
					<< endl
					<< "                客房管理系统" << endl
					<< endl
					<< "      ----------------------------------" << endl
					<< endl;
				while (q != NULL)
				{
					if (q->State != 1 and q->Price != 0)
					{
						cout << endl;
						cout << "房间编号：" << q->Number << "  ";
						cout << "房间类型：" << q->Type << "  ";
						cout << "房间单价：" << q->Price << "  ";
					}
					q = q->next;
				}
				cout << endl;
				cout << "  请选择房间（输入房间号）：" << endl;
				string changenumber;
				cin >> changenumber;
				q = RoomList;
				while (q != NULL)
				{
					if (changenumber == q->Number)
					{
						q->State = 1;
						p->InRoomNumber = changenumber;
						p->Cost = q->Price * GetInDays(InYear, InMonth, InDay, OutYear, OutMonth, OutDay);
						system("cls");
						cout << endl
							<< endl
							<< "                客房管理系统" << endl
							<< endl
							<< "      ----------------------------------" << endl
							<< endl
							<< "            已更新客房与客人信息。" << endl;
						system("pause");
						system("cls");
						Room* clear = RoomList;
						while (clear != NULL)
						{
							if (clear->Number == inroomnumber)
							{
								clear->State = 0;
							}
							clear = clear->next;
						}
						return;
					}
					q = q->next;
				}
				system("cls");
				cout << endl
					<< endl
					<< "                客房管理系统" << endl
					<< endl
					<< "      ----------------------------------" << endl
					<< endl
					<< "        房间编号输入错误，请重新输入。" << endl;
				system("pause");
				goto ShowRoom;
			}
			system("cls");
			cout << endl
				<< endl
				<< "                客房管理系统" << endl
				<< endl
				<< "      ----------------------------------" << endl
				<< endl
				<< "            已更新客房与客人信息。" << endl;
			system("pause");
			system("cls");
			return;
		}
		p = p->next;
	}
	cout << "                 无该客人信息。";
	system("pause");
	system("cls");
}