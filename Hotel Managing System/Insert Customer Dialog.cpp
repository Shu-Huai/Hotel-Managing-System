﻿#include "Insert Customer Dialog.h"
#include <QMessageBox>
#include <QFile>
InsertCustomerDialog::InsertCustomerDialog(CustomerList& customerList, RoomList& roomList, QWidget* parent) : QDialog(parent), customerList_(customerList), roomList_(roomList)
{
	ui_ = new Ui::InsertCustomerDialog;
	ui_->setupUi(this);
	connect(ui_->confirmButton, SIGNAL(clicked()), this, SLOT(InsertCustomer()));
	connect(ui_->clearButton, SIGNAL(clicked()), this, SLOT(ClearEditor()));
	connect(ui_->returButton, SIGNAL(clicked()), this, SLOT(close()));
	for (int i = 0; i < roomList_.GetLength(); i++)
	{
		int number = 0;
		QString type = "";
		int price = 0;
		bool isFull = false;
		roomList_.GetRoom(i, number, type, price, isFull);
		if (isFull)
		{
			continue;
		}
		QString item;
		item.append(QString("%1 ").arg(number, 4, 10, QLatin1Char(' ')));
		item.append(QString("%1 ").arg(price, 4, 10, QLatin1Char(' ')));
		item.append(type);
		ui_->roomCombo->addItem(item);
	}
	ui_->roomCombo->setCurrentIndex(-1);
}
InsertCustomerDialog::~InsertCustomerDialog()
{
	delete ui_;
}
void InsertCustomerDialog::InsertCustomer()
{
	if (ui_->nameEdit->text() == "" || ui_->IDEdit->text() == "" || ui_->roomCombo->currentText() == "" || ui_->dayEdit->text() == "")
	{
		QMessageBox box(QMessageBox::Critical, "错误", "空白的输入。");
		box.setWindowIcon(QIcon(":/HotelManagingSystem/Error Icon.ico"));
		box.setIconPixmap(QPixmap(":/HotelManagingSystem/Error Icon.ico").scaled(32, 32));
		box.setFont(QFont("宋体", 12));
		box.addButton("确定", QMessageBox::AcceptRole)->setFont(QFont("宋体", 12));
		box.exec();
		return;
	}
	QString ID = ui_->IDEdit->text();
	if (customerList_.IsCustomerExist(ID))
	{
		QMessageBox box(QMessageBox::Critical, "错误", "客人已存在。");
		box.setWindowIcon(QIcon(":/HotelManagingSystem/Error Icon.ico"));
		box.setIconPixmap(QPixmap(":/HotelManagingSystem/Error Icon.ico").scaled(32, 32));
		box.setFont(QFont("宋体", 12));
		box.addButton("确定", QMessageBox::AcceptRole)->setFont(QFont("宋体", 12));
		box.exec();
		ui_->IDEdit->clear();
		return;
	}
	QString name = ui_->nameEdit->text();
	QString roomNumber = ui_->roomCombo->currentText().trimmed().section(" ", 0, 0);
	QString day = ui_->dayEdit->text();
	customerList_.InsertCustomer(name, ID, roomNumber.toInt(), day.toInt());
	roomList_.SetFull(roomNumber.toInt());
	QFile customerFile("Customer.txt");
	customerFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
	QTextStream out(&customerFile);
	out << '\n' << name << " " << ID << " " << roomNumber << " " << day;
	customerFile.close();
	QMessageBox box(QMessageBox::Information, "成功", "操作成功。");
	box.setWindowIcon(QIcon(":/HotelManagingSystem/Information Icon.ico"));
	box.setIconPixmap(QPixmap(":/HotelManagingSystem/Information Icon.ico").scaled(32, 32));
	box.setFont(QFont("宋体", 12));
	box.addButton("确定", QMessageBox::AcceptRole)->setFont(QFont("宋体", 12));
	box.exec();
	ClearEditor(false);
}
void InsertCustomerDialog::ClearEditor(bool isButtonPushed)
{
	if (ui_->nameEdit->text() != "" || ui_->IDEdit->text() != "" || ui_->roomCombo->currentText() != "" || ui_->dayEdit->text() != "")
	{
		if (isButtonPushed)
		{
			QMessageBox box(QMessageBox::Warning, "警告", "将要清除输入。");
			box.setWindowIcon(QIcon(":/HotelManagingSystem/Warning Icon.ico"));
			box.setIconPixmap(QPixmap(":/HotelManagingSystem/Warning Icon.ico").scaled(32, 32));
			box.setFont(QFont("宋体", 12));
			box.addButton("确定", QMessageBox::YesRole)->setFont(QFont("宋体", 12));
			box.addButton("取消", QMessageBox::NoRole)->setFont(QFont("宋体", 12));
			if (box.exec())
			{
				return;
			}
		}
		ui_->nameEdit->clear();
		ui_->IDEdit->clear();
		ui_->roomCombo->setCurrentIndex(-1l);
		ui_->dayEdit->clear();
	}
}