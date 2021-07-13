#include "Insert Customer Dialog.h"
#include <QMessageBox>
InsertCustomerDialog::InsertCustomerDialog(CustomerList& customerList, RoomList& roomList, QWidget* parent) : QDialog(parent), customerList_(customerList), roomList_(roomList)
{
	ui_.setupUi(this);
	connect(ui_.confirmButton, SIGNAL(clicked()), this, SLOT(InsertCustomer()));
	connect(ui_.clearButton, SIGNAL(clicked()), this, SLOT(ClearEdit()));
	connect(ui_.returButton, SIGNAL(clicked()), this, SLOT(close()));
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
		ui_.roomCombo->addItem(item);
	}
	ui_.roomCombo->setCurrentIndex(-1);
}
InsertCustomerDialog::~InsertCustomerDialog()
{
}
void InsertCustomerDialog::InsertCustomer()
{
}
void InsertCustomerDialog::ClearEdit(bool isButtonPushed)
{
	if (ui_.nameEdit->text() != "" || ui_.IDEdit->text() != "" || ui_.roomCombo->currentText() != "")
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
		ui_.nameEdit->clear();
		ui_.IDEdit->clear();
		ui_.roomCombo->setCurrentIndex(-1l);
	}
}