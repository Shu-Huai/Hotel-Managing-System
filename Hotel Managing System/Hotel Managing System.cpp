#include "Hotel Managing System.h"
HotelManagingSystem::HotelManagingSystem(QWidget* parent) : QMainWindow(parent), insertDialog_(NULL)
{
	ui_ = new Ui::HotelManagementClass;
	ui_->setupUi(this);
	connect(ui_->insertButton, SIGNAL(clicked()), this, SLOT(Insert()));
	connect(ui_->exitButton, SIGNAL(clicked()), this, SLOT(close()));
	QFile RoomFile("Room.txt");
	RoomFile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream inp(&RoomFile);
	while (!inp.atEnd())
	{
		int number = 0;
		QString type = "";
		int price = 0;
		int state = 0;
		inp >> number >> type >> price >> state;
		roomList_.Insert(number, type, price, bool(state));
	}
	RoomFile.close();
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
	insertDialog_->exec();
	delete insertDialog_;
}