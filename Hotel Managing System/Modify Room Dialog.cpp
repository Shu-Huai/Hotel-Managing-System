#include "Modify Room Dialog.h"
#include <QMessageBox>
ModifyRoomDialog::ModifyRoomDialog(RoomList& list, QWidget* parent) : QDialog(parent), list_(list)
{
	ui_ = new Ui::ModifyRoomDialog;
	ui_->setupUi(this);
	connect(ui_->roomCombo, SIGNAL(activated(int)), this, SLOT(SetEdit(int)));
	connect(ui_->modifyButton, SIGNAL(clicked()), this, SLOT(Modify()));
	connect(ui_->returnButton, SIGNAL(clicked()), this, SLOT(close()));
	for (int i = 0; i < list.GetLength(); i++)
	{
		int number = 0;
		QString type = "";
		int price = 0;
		bool isFull = false;
		list_.GetRoom(i, number, type, price, isFull);
		QString item;
		item.append(QString("%1 ").arg(number, 4, 10, QLatin1Char(' ')));
		item.append(type);
		item.append(QString(" %1 ").arg(price, 4, 10, QLatin1Char(' ')));
		item.append(isFull ? "满" : "空");
		ui_->roomCombo->addItem(item);
		if (isFull)
		{
			ui_->roomCombo->setItemData(i, 0, Qt::UserRole - 1);
		}
	}
	ui_->roomCombo->setCurrentIndex(-1);
}
ModifyRoomDialog::~ModifyRoomDialog()
{
	delete ui_;
}
void ModifyRoomDialog::SetEdit(int index)
{
	int number = 0;
	QString type = "";
	int price = 0;
	bool isFull = false;
	list_.GetRoom(ui_->roomCombo->currentIndex(), number, type, price, isFull);
	ui_->numberEdit->setText(QString("%1").arg(number));
	ui_->typeEdit->setText(type);
	ui_->priceEdit->setText(QString("%1").arg(price));
}
void ModifyRoomDialog::Modify()
{
	QString roomNumber = ui_->roomCombo->currentText().trimmed().section(" ", 0, 0);
	list_.SetRoom(ui_->roomCombo->currentIndex(), ui_->numberEdit->text().toInt(), ui_->typeEdit->text(), ui_->priceEdit->text().toInt(), false);
	QString itemText;
	itemText.append(QString("%1 ").arg(ui_->numberEdit->text().toInt(), 4, 10, QLatin1Char(' ')));
	itemText.append(ui_->typeEdit->text());
	itemText.append(QString(" %1 空").arg(ui_->priceEdit->text().toInt(), 4, 10, QLatin1Char(' ')));
	ui_->roomCombo->setItemText(ui_->roomCombo->currentIndex(), itemText);
	QMessageBox box(QMessageBox::Information, "成功", "操作成功。", QMessageBox::NoButton, this);
	box.setWindowIcon(QIcon(":/HotelManagingSystem/Information Icon.ico"));
	box.setIconPixmap(QPixmap(":/HotelManagingSystem/Information Icon.ico").scaled(32, 32));
	box.setFont(QFont("宋体", 12));
	box.addButton("确定", QMessageBox::AcceptRole)->setFont(QFont("宋体", 12));
	box.exec();
}