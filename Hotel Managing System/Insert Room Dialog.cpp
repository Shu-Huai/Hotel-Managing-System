#include "Insert Room Dialog.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QString>
InsertRoomDialog::InsertRoomDialog(QWidget* parent)
	: QDialog(parent)
{
	ui_.setupUi(this);
	connect(ui_.confirmButton, SIGNAL(clicked()), this, SLOT(on_btnConfirmPush_clicked()));
	connect(ui_.clearButton, SIGNAL(clicked()), this, SLOT(on_btnClearPush_clicked()));
	connect(ui_.returnButton, SIGNAL(clicked()), this, SLOT(close()));
}
InsertRoomDialog::~InsertRoomDialog()
{
}
void InsertRoomDialog::on_btnConfirmPush_clicked()
{
	if (ui_.numberEdit->text() == "" || ui_.typeEdit->text() == "" || ui_.priceEdit->text() == "")
	{
		QMessageBox::information(this, "Error", "Missing fact/s.");
		return;
	}
	int number = ui_.numberEdit->text().toInt();
	if (list_.IsRoomExist(number))
	{
		QMessageBox::information(this, "Error", "Room Exists.");
		ui_.numberEdit->clear();
		return;
	}
	QString type = ui_.typeEdit->text();
	int price = ui_.priceEdit->text().toInt();
	list_.Insert(number, type, price, 0);
	QFile RoomFile("Room.txt");
	RoomFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
	QTextStream out(&RoomFile);
	out << number << " " << type << " " << price << " " << 0 << '\n';
	RoomFile.close();
	QMessageBox::information(this, "Success", "Operation succeeded.");
	on_btnClearPush_clicked(1);
}
void InsertRoomDialog::on_btnClearPush_clicked(bool flag)
{
	if (!flag)
	{
		if (QMessageBox::information(this, "Confirm", "Are you sure to clear input? ", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) == QMessageBox::No)
		{
			return;
		}
	}
	ui_.numberEdit->clear();
	ui_.typeEdit->clear();
	ui_.priceEdit->clear();
}