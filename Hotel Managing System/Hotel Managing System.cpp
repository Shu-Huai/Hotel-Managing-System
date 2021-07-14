#include "Hotel Managing System.h"
HotelManagingSystem::HotelManagingSystem(QWidget* parent) : QMainWindow(parent), insertDialog_(NULL), deleteRoomDialog_(NULL), checkOutDialog_(NULL)
{
	ui_ = new Ui::HotelManagementClass;
	ui_->setupUi(this);
	connect(ui_->insertButton, SIGNAL(clicked()), this, SLOT(Insert()));
	connect(ui_->exitButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui_->deleteRoomButton, SIGNAL(clicked()), this, SLOT(DeleteRoom()));
	connect(ui_->checkOutButton, SIGNAL(clicked()), this, SLOT(CheckOut()));
	QFile roomFile("Room.txt");
	roomFile.open(QIODevice::ReadWrite | QIODevice::Text);
	QTextStream roomIn(&roomFile);
	while (!roomIn.atEnd())
	{
		int number = 0;
		QString type = "";
		int price = 0;
		int state = 0;
		roomIn >> number >> type >> price >> state;
		roomList_.Insert(number, type, price, bool(state));
	}
	roomFile.close();
	QFile customerFile("Customer.txt");
	customerFile.open(QIODevice::ReadWrite | QIODevice::Text);
	QTextStream customerIn(&customerFile);
	while (!customerIn.atEnd())
	{
		QString name = "";
		QString ID = "";
		int roomNumber = 0;
		int day = 0;
		customerIn >> name >> ID >> roomNumber >> day;
		customerList_.InsertCustomer(name, ID, roomNumber, day);
		roomList_.SetFull(roomNumber);
	}
	customerFile.close();
}
HotelManagingSystem::~HotelManagingSystem()
{
	delete ui_;
}
void HotelManagingSystem::Exit()
{
	QFile roomFile("Room.txt");
	roomFile.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream roomOut(&roomFile);
	for (int i = 0; i < roomList_.GetLength(); i++)
	{
		int number = 0;
		QString type = "";
		int price = 0;
		bool isFull = false;
		roomList_.GetRoom(i, number, type, price, isFull);
		roomOut << number << " " << type << " " << price << " " << isFull;
		if (i != roomList_.GetLength() - 1)
		{
			roomOut << '\n';
		}
	}
	roomFile.close();

	QFile customerFile("Customer.txt");
	customerFile.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream customerOut(&customerFile);
	for (int i = 0; i < customerList_.GetLength(); i++)
	{
		QString name = "";
		QString ID = "";
		int number = 0;
		int day = 0;
		customerList_.GetCustomer(i, name, ID, number, day);
		customerOut << name << " " << ID << " " << number << " " << day;
		if (i != customerList_.GetLength() - 1)
		{
			customerOut << '\n';
		}
	}
	customerFile.close();
}
void HotelManagingSystem::Insert()
{
	insertDialog_ = new InsertDialog(customerList_, roomList_);
	insertDialog_->setWindowIcon(QIcon(":/HotelManagingSystem/Hotel Managing System Window Icon.ico"));
	insertDialog_->setWindowTitle("插入");
	insertDialog_->exec();
	delete insertDialog_;
}
void HotelManagingSystem::DeleteRoom()
{
	deleteRoomDialog_ = new DeleteRoomDialog(roomList_);
	deleteRoomDialog_->setWindowIcon(QIcon(":/HotelManagingSystem/Hotel Managing System Window Icon.ico"));
	deleteRoomDialog_->setWindowTitle("删房");
	deleteRoomDialog_->exec();
	delete deleteRoomDialog_;
}
void HotelManagingSystem::CheckOut()
{
	checkOutDialog_ = new CheckOutDialog(customerList_, roomList_);
	checkOutDialog_->setWindowIcon(QIcon(":/HotelManagingSystem/Hotel Managing System Window Icon.ico"));
	checkOutDialog_->setWindowTitle("退房");
	checkOutDialog_->exec();
	delete checkOutDialog_;
}