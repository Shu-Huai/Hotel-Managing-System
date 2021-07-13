#include "Hotel Managing System.h"
HotelManagingSystem::HotelManagingSystem(QWidget* parent) : QMainWindow(parent), insertDialog_(NULL)
{
	ui_ = new Ui::HotelManagementClass;
	ui_->setupUi(this);
	connect(ui_->insertButton, SIGNAL(clicked()), this, SLOT(Insert()));
	connect(ui_->exitButton, SIGNAL(clicked()), this, SLOT(close()));
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
		customerIn >> name >> ID >> roomNumber;
		customerList_.Insert(name, ID, roomNumber);
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
	QFile RoomFile("Room.txt");
	RoomFile.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream out(&RoomFile);
	for (int i = 0; i < roomList_.GetLength(); i++)
	{
		int number = 0;
		QString type = "";
		int price = 0;
		bool isFull = false;
		roomList_.GetRoom(i, number, type, price, isFull);
		out << number << " " << type << " " << price << " " << isFull;
		if (i != roomList_.GetLength() - 1)
		{
			out << '\n';
		}
	}
	RoomFile.close();
}
void HotelManagingSystem::Insert()
{
	insertDialog_ = new InsertDialog(customerList_, roomList_);
	insertDialog_->setWindowIcon(QIcon(":/HotelManagingSystem/Hotel Managing System Window Icon.ico"));
	insertDialog_->setWindowTitle("插入");
	insertDialog_->exec();
	delete insertDialog_;
}