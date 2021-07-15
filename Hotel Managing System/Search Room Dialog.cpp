#include "Search Room Dialog.h"
#include <QMessageBox>
SearchRoomDialog::SearchRoomDialog(RoomList& list, QWidget* parent) : QDialog(parent), list_(list)
{
	ui_ = new Ui::SearchRoomDialog;
	ui_->setupUi(this);
	connect(ui_->numberEdit, SIGNAL(textEdited(QString)), this, SLOT(SearchRoom(QString)));
	connect(ui_->typeEdit, SIGNAL(textEdited(QString)), this, SLOT(SearchRoom(QString)));
	connect(ui_->priceEdit, SIGNAL(textEdited(QString)), this, SLOT(SearchRoom(QString)));
	connect(ui_->isFullEdit, SIGNAL(textEdited(QString)), this, SLOT(SearchRoom(QString)));
	connect(ui_->clearButton, SIGNAL(clicked()), this, SLOT(ClearEditor()));
	connect(ui_->returnButton, SIGNAL(clicked()), this, SLOT(close()));
	for (int i = 0; i < list_.GetLength(); i++)
	{
		QString item = "";
		item.append(QString("%1 ").arg(list_.GetRoomNumber(i), 4, 10, QLatin1Char(' ')));
		item.append(list_.GetRoomType(i));
		item.append(QString(" %1").arg(list_.GetRoomPrice(i), 4, 10, QLatin1Char(' ')));
		item.append(list_.GetRoomState(i) ? " 满" : " 空");
		ui_->roomList->addItem(item);
	}
}
SearchRoomDialog::~SearchRoomDialog()
{
	delete ui_;
}
void SearchRoomDialog::SearchRoom(QString text)
{
	ui_->roomList->clear();
	int number = ui_->numberEdit->text() == "" ? -1 : ui_->numberEdit->text().toInt();
	QString type = ui_->typeEdit->text();
	int price = ui_->priceEdit->text() == "" ? -1 : ui_->priceEdit->text().toInt();
	int isFull = ui_->isFullEdit->text() == "" ? -1 : ui_->isFullEdit->text() == "满" ? 1 : ui_->isFullEdit->text() == "空" ? 0 : 2;
	RoomList& list = list_.SearchRoom(number, type, price, isFull);
	for (int i = 0; i < list.GetLength(); i++)
	{
		QString item = "";
		item.append(QString("%1 ").arg(list.GetRoomNumber(i), 4, 10, QLatin1Char(' ')));
		item.append(list.GetRoomType(i));
		item.append(QString(" %1").arg(list.GetRoomPrice(i), 4, 10, QLatin1Char(' ')));
		item.append(list.GetRoomState(i) ? " 满" : " 空");
		ui_->roomList->addItem(item);
	}
	delete& list;
}
void SearchRoomDialog::ClearEditor()
{
	if (ui_->numberEdit->text() != "" || ui_->typeEdit->text() != "" || ui_->priceEdit->text() != "" || ui_->isFullEdit->text() != "")
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
		ui_->numberEdit->clear();
		ui_->typeEdit->clear();
		ui_->priceEdit->clear();
		ui_->isFullEdit->clear();
	}
}