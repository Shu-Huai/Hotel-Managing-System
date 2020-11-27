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
		<< "                �ͷ�����ϵͳ" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "����������ס�Ŀ��˵������Ϣ�����֤�ţ���";
	cin >> TempCustomer->ID;
	Customer* p = CustomerList;
	while (p != NULL)
	{
		if (p->ID == TempCustomer->ID)
		{
			system("cls");
			cout << endl
				<< endl
				<< "                �ͷ�����ϵͳ" << endl
				<< endl
				<< "      ----------------------------------" << endl
				<< endl
				<< "�ÿ����Ѵ��ڣ������޸�������Y,�ص����˵�������������ĸ��";
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
	cout << "����������ס�Ŀ��˵�������";
	cin >> TempCustomer->Name;
	cout << "����������ס�ÿ�����ס���ڣ�";
	cin >> TempCustomer->InDate;
	cout << "����������ס�ÿ����˷����ڣ�";
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
		<< "                �ͷ�����ϵͳ" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl;
	if (q == NULL)
	{
		cout << "              ����¼��ͷ���Ϣ��";
		system("pause");
		return;
	}
ShowRoom:
	while (q != NULL)
	{
		if (q->State != 1 and q->Price != 0)
		{
			cout << endl;
			cout << "�����ţ�" << q->Number << "  ";
			cout << "�������ͣ�" << q->Type << "  ";
			cout << "���䵥�ۣ�" << q->Price << "  ";
			i = 1;
		}
		q = q->next;
	}
	if (q == NULL and i == 0)
	{
		cout << "   ���޿շ��䡣";
		system("pause");
		return;
	}
	cout << endl
		<< "  ��ѡ�񷿼䣨���뷿��ţ���" << endl;
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
			<< "                �ͷ�����ϵͳ" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "            �Ѹ��¿ͷ��������Ϣ��" << endl;
		system("pause");
		system("cls");
		TempCustomer->next = CustomerList;
		CustomerList = TempCustomer;
	}
	else
	{
		cout << endl
			<< endl
			<< "                �ͷ�����ϵͳ" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "        ����������������������롣" << endl
			<< endl;
		goto ShowRoom;
	}
}
void SearchCustomer(Customer*& CustomerList)
{
	cout << endl
		<< endl
		<< "                �ͷ�����ϵͳ" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "      ����������ҵĿ������������֤��";
	string input;
	cin >> input;
	bool judge = 0;
	Customer* p = CustomerList;
	while (p != NULL)
	{
		if (input == p->Name or input == p->ID)
		{
			cout << endl
				<< "��������" << p->Name << endl
				<< endl
				<< "�������֤��" << p->ID << endl
				<< endl
				<< "������סʱ��" << p->InDate << endl
				<< endl
				<< "�����˷�ʱ��" << p->OutDate << endl
				<< endl
				<< "������ס����" << p->InRoomNumber << endl
				<< endl
				<< "�������ѽ��" << p->Cost << endl
				<< endl;
			judge = 1;
		}
		p = p->next;
	}
	if (judge == 0)
	{
		cout << endl
			<< endl
			<< "                �ͷ�����ϵͳ" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "		          ���޴��ˡ�" << endl;
	}
	system("pause");
	system("cls");
}
void ShowCustomer(Customer*& CustomerList)
{
	cout << endl
		<< endl
		<< "                �ͷ�����ϵͳ" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl;
	bool judge = 0;
	Customer* p = CustomerList;
	while (p != NULL)
	{
		cout << "��������" << p->Name << "    "
			<< "�������֤��" << p->ID << "   "
			<< "������סʱ��" << p->InDate << "   "
			<< "�����˷�ʱ��" << p->OutDate << "  "
			<< "������ס����" << p->InRoomNumber << "  "
			<< "�������ѽ��" << p->Cost << endl
			<< endl;
		judge = 1;
		p = p->next;
	}
	if (judge == 0)
		cout << "             ���޿�����Ϣ��" << endl
		<< endl;
	system("pause");
	system("cls");
}
void CheckOut(Room*& RoomList, Customer*& CustomerList)
{
	cout << endl
		<< endl
		<< "                �ͷ�����ϵͳ" << endl
		<< endl
		<< "      ----------------------------------" << endl
		<< endl
		<< "       �������˷��������֤�Ż�������";
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
			<< "                �ͷ�����ϵͳ" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "       �����˷��ɹ�����֧��: " << pay << endl;
	}
	else
	{
		cout << endl
			<< endl
			<< "                �ͷ�����ϵͳ" << endl
			<< endl
			<< "      ----------------------------------" << endl
			<< endl
			<< "                �ÿ��˲����ڡ�" << endl;
	}
	system("pause");
	system("cls");
}