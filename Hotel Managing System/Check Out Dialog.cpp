#include "Check Out Dialog.h"
#include <QCheckBox>
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
		customerList_.GetCustomer(i, name, ID, number);
		QString itemText;
		itemText.append(name);
		itemText.append(" ");
		itemText.append(ID);
		itemText.append(QString(" %1").arg(number, 4, 10, QLatin1Char(' ')));
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
			int roomNumber = customerList_.GetCustomerRoomNumber(i);
			customerList_.DeleteCustomer(i);
			roomList_.CheckOut(roomNumber);
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