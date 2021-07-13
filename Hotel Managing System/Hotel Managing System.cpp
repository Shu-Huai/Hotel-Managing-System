#include "Hotel Managing System.h"
HotelManagingSystem::HotelManagingSystem(QWidget* parent)
	: QMainWindow(parent)
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
		list_.Insert(number, type, price, state);
	}
	list_.DeleteRoom();
	RoomFile.close();
}
void HotelManagingSystem::Insert()
{
	insertDialog_ = new InsertDialog;
	insertDialog_->list_ = list_;
	insertDialog_->exec();
	list_ = insertDialog_->list_;
	delete insertDialog_;
}