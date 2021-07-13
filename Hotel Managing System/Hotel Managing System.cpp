#include "Hotel Managing System.h"
HotelManagingSystem::HotelManagingSystem(QWidget* parent) : QMainWindow(parent), insertDialog_(NULL)
{
	ui_.setupUi(this);
	connect(ui_.insertButton, SIGNAL(clicked()), this, SLOT(Insert()));
	connect(ui_.exitButton, SIGNAL(clicked()), this, SLOT(close()));
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
		list_.Insert(number, type, price, bool(state));
	}
	list_.DeleteRoom(list_.GetLength() - 1);
	RoomFile.close();
}
void HotelManagingSystem::Exit()
{
	QFile RoomFile("Room.txt");
	RoomFile.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream out(&RoomFile);
	for (int i = 0; i < list_.GetLength(); i++)
	{
		int number = 0;
		QString type = "";
		int price = 0;
		bool state = false;
		list_.GetRoom(i, number, type, price, state);
		out << number << " " << type << " " << price << " " << state;
		if (i != list_.GetLength() - 1)
		{
			out << '\n';
		}
	}
	RoomFile.close();
}
void HotelManagingSystem::Insert()
{
	insertDialog_ = new InsertDialog(list_);
	insertDialog_->exec();
	delete insertDialog_;
}