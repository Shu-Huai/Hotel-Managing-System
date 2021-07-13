﻿#include "Insert Room Dialog.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QString>
InsertRoomDialog::InsertRoomDialog(RoomList& list, QWidget* parent) : QDialog(parent), list_(list)
{
	ui_.setupUi(this);
	connect(ui_.confirmButton, SIGNAL(clicked()), this, SLOT(InsertRoom()));
	connect(ui_.clearButton, SIGNAL(clicked()), this, SLOT(ClearEdit()));
	connect(ui_.returnButton, SIGNAL(clicked()), this, SLOT(close()));
}
InsertRoomDialog::~InsertRoomDialog()
{
}
void InsertRoomDialog::InsertRoom()
{
	if (ui_.numberEdit->text() == "" || ui_.typeEdit->text() == "" || ui_.priceEdit->text() == "")
	{
		QMessageBox box(QMessageBox::Critical, "错误", "空白的输入。");
		box.setWindowIcon(QIcon(":/HotelManagement/Error Icon.ico"));
		box.setIconPixmap(QPixmap(":/HotelManagement/Error Icon.ico").scaled(32, 32));
		box.setFont(QFont("宋体", 12));
		box.addButton("确定", QMessageBox::AcceptRole)->setFont(QFont("宋体", 12));
		box.exec();
		return;
	}
	int number = ui_.numberEdit->text().toInt();
	if (list_.IsRoomExist(number))
	{
		QMessageBox box(QMessageBox::Critical, "错误", "房间已存在。");
		box.setWindowIcon(QIcon(":/HotelManagement/Error Icon.ico"));
		box.setIconPixmap(QPixmap(":/HotelManagement/Error Icon.ico").scaled(32, 32));
		box.setFont(QFont("宋体", 12));
		box.addButton("确定", QMessageBox::AcceptRole)->setFont(QFont("宋体", 12));
		box.exec();
		ui_.numberEdit->clear();
		return;
	}
	QString type = ui_.typeEdit->text();
	int price = ui_.priceEdit->text().toInt();
	list_.Insert(number, type, price, 0);

	QMessageBox box(QMessageBox::Information, "成功", "操作成功。");
	box.setWindowIcon(QIcon(":/HotelManagement/Information Icon.ico"));
	box.setIconPixmap(QPixmap(":/HotelManagement/Information Icon.ico").scaled(32, 32));
	box.setFont(QFont("宋体", 12));
	box.addButton("确定", QMessageBox::AcceptRole)->setFont(QFont("宋体", 12));
	box.exec();
	ClearEdit(false);
}
void InsertRoomDialog::ClearEdit(bool isButtonPushed)
{
	if (ui_.numberEdit->text() != "" || ui_.typeEdit->text() != "" || ui_.priceEdit->text() != "")
	{
		if (isButtonPushed)
		{
			QMessageBox box(QMessageBox::Warning, "警告", "将要清除输入。");
			box.setWindowIcon(QIcon(":/HotelManagement/Warning Icon.ico"));
			box.setIconPixmap(QPixmap(":/HotelManagement/Warning Icon.ico").scaled(32, 32));
			box.setFont(QFont("宋体", 12));
			box.addButton("确定", QMessageBox::YesRole)->setFont(QFont("宋体", 12));
			box.addButton("取消", QMessageBox::NoRole)->setFont(QFont("宋体", 12));
			if (box.exec())
			{
				return;
			}
		}
		ui_.numberEdit->clear();
		ui_.typeEdit->clear();
		ui_.priceEdit->clear();
	}
}