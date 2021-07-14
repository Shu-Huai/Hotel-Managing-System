#include "Check Out Dialog.h"
#include <QCheckBox>
#include <QMessageBox>
#include <QList>
#include <QListWidget>
CheckOutDialog::CheckOutDialog(CustomerList& customerList, RoomList& roomList, QWidget* parent) : QDialog(parent), customerList_(customerList), roomList_(roomList)
{
	ui_ = new Ui::CheckOutDialog;
	ui_->setupUi(this);

	connect(ui_->checkOutButton, SIGNAL(clicked()), this, SLOT(CheckOut()));
	connect(ui_->returnButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui_->selectAll, SIGNAL(clicked()), this, SLOT(SelectAll()));
	connect(ui_->selectNone, SIGNAL(clicked()), this, SLOT(SelectNone()));
	connect(ui_->selectReverse, SIGNAL(clicked()), this, SLOT(SelectReverse()));
	for (int i = 0; i < customerList_.GetLength(); i++)
	{
		QString name = "";
		QString ID = "";
		int number = 0;
		int day = 0;
		customerList_.GetCustomer(i, name, ID, number, day);
		QString itemText;
		itemText.append(name);
		itemText.append(" ");
		itemText.append(ID);
		itemText.append(QString(" %1").arg(number, 4, 10, QLatin1Char(' ')));
		itemText.append(QString(" %1天").arg(day, 2, 10, QLatin1Char(' ')));
		QListWidgetItem* item = new QListWidgetItem;
		QCheckBox* checkBox = new QCheckBox();
		ui_->customerList->addItem(item);
		ui_->customerList->setItemWidget(item, checkBox);
		checkBox->setText(itemText);
	}
}
CheckOutDialog::~CheckOutDialog()
{
	ui_->customerList->clear();
	delete ui_;
}
void CheckOutDialog::CheckOut()
{
	for (int i = 0; i < ui_->customerList->count(); i++)
	{
		QListWidgetItem* item = ui_->customerList->item(i);
		QCheckBox* checkBox = static_cast<QCheckBox*>(ui_->customerList->itemWidget(item));
		if (checkBox->isChecked())
		{
			QString name = customerList_.GetCustomerName(i);
			int roomNumber = customerList_.GetCustomerRoomNumber(i);
			int day = customerList_.GetCustomerDay(i);
			customerList_.DeleteCustomer(i);
			int roomPrice = roomList_.GetRoomPrice(roomNumber);
			roomList_.CheckOut(roomNumber);
			int price = day * roomPrice;
			QMessageBox box(QMessageBox::Information, "成功", QString("%1需支付%2。").arg(name).arg(price));
			box.setWindowIcon(QIcon(":/HotelManagingSystem/Information Icon.ico"));
			box.setIconPixmap(QPixmap(":/HotelManagingSystem/Information Icon.ico").scaled(32, 32));
			box.setFont(QFont("宋体", 12));
			box.addButton("确定", QMessageBox::AcceptRole)->setFont(QFont("宋体", 12));
			box.exec();
			delete ui_->customerList->takeItem(i);
			i--;
		}
	}
}
void CheckOutDialog::SelectAll()
{
	for (int i = 0; i < ui_->customerList->count(); i++)
	{
		QListWidgetItem* item = ui_->customerList->item(i);
		QCheckBox* checkBox = static_cast<QCheckBox*>(ui_->customerList->itemWidget(item));
		checkBox->setChecked(true);
	}
}
void CheckOutDialog::SelectNone()
{
	for (int i = 0; i < ui_->customerList->count(); i++)
	{
		QListWidgetItem* item = ui_->customerList->item(i);
		QCheckBox* checkBox = static_cast<QCheckBox*>(ui_->customerList->itemWidget(item));
		checkBox->setChecked(false);
	}
}
void CheckOutDialog::SelectReverse()
{
	for (int i = 0; i < ui_->customerList->count(); i++)
	{
		QListWidgetItem* item = ui_->customerList->item(i);
		QCheckBox* checkBox = static_cast<QCheckBox*>(ui_->customerList->itemWidget(item));
		checkBox->setChecked(!checkBox->isChecked());
	}
}