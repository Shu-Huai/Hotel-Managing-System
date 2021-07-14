#include "Delete Room Dialog.h"
#include <QCheckbox>
#include <QListWidget>
DeleteRoomDialog::DeleteRoomDialog(RoomList& list, QWidget* parent) : QDialog(parent), list_(list)
{
	ui_ = new Ui::DeleteRoomDialog;
	ui_->setupUi(this);
	connect(ui_->deleteButton, SIGNAL(clicked()), this, SLOT(DeleteRoom()));
	connect(ui_->returnButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui_->selectAll, SIGNAL(clicked()), this, SLOT(SelectAll()));
	connect(ui_->selectNone, SIGNAL(clicked()), this, SLOT(SelectNone()));
	connect(ui_->selectReverse, SIGNAL(clicked()), this, SLOT(SelectReverse()));
	for (int i = 0; i < list_.GetLength(); i++)
	{
		int number = 0;
		QString type = "";
		int price = 0;
		bool isFull = false;
		list_.GetRoom(i, number, type, price, isFull);
		QString itemText;
		itemText.append(QString("%1 ").arg(number, 4, 10, QLatin1Char(' ')));
		itemText.append(QString("%1 ").arg(price, 4, 10, QLatin1Char(' ')));
		itemText.append(type);
		itemText.append(isFull ? " 满" : " 空");
		QListWidgetItem* item = new QListWidgetItem;
		QCheckBox* checkBox = new QCheckBox();
		ui_->roomListWidget->addItem(item);
		ui_->roomListWidget->setItemWidget(item, checkBox);
		checkBox->setText(itemText);
		checkBox->setDisabled(isFull);
	}
}
DeleteRoomDialog::~DeleteRoomDialog()
{
	delete ui_;
}
void DeleteRoomDialog::DeleteRoom()
{
	for (int i = 0; i < ui_->roomListWidget->count(); i++)
	{
		QListWidgetItem* item = ui_->roomListWidget->item(i);
		QCheckBox* checkBox = static_cast<QCheckBox*>(ui_->roomListWidget->itemWidget(item));
		if (checkBox->isChecked())
		{
			list_.DeleteRoom(i);
			delete ui_->roomListWidget->takeItem(i);
			i--;
		}
	}
}
void DeleteRoomDialog::SelectAll()
{
	for (int i = 0; i < ui_->roomListWidget->count(); i++)
	{
		QListWidgetItem* item = ui_->roomListWidget->item(i);
		QCheckBox* checkBox = static_cast<QCheckBox*>(ui_->roomListWidget->itemWidget(item));
		if (checkBox->isEnabled())
		{
			checkBox->setChecked(true);
		}
	}
}
void DeleteRoomDialog::SelectNone()
{
	for (int i = 0; i < ui_->roomListWidget->count(); i++)
	{
		QListWidgetItem* item = ui_->roomListWidget->item(i);
		QCheckBox* checkBox = static_cast<QCheckBox*>(ui_->roomListWidget->itemWidget(item));
		checkBox->setChecked(false);
	}
}
void DeleteRoomDialog::SelectReverse()
{
	for (int i = 0; i < ui_->roomListWidget->count(); i++)
	{
		QListWidgetItem* item = ui_->roomListWidget->item(i);
		QCheckBox* checkBox = static_cast<QCheckBox*>(ui_->roomListWidget->itemWidget(item));
		if (checkBox->isEnabled())
		{
			checkBox->setChecked(!checkBox->isChecked());
		}
	}
}