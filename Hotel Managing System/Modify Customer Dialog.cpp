#include "Modify Customer Dialog.h"
#include <QMessageBox>
ModifyCustomerDialog::ModifyCustomerDialog(CustomerList& list, QWidget* parent) : QDialog(parent), list_(list)
{
	ui_ = new Ui::ModifyCustomerDialog;
	ui_->setupUi(this);
	connect(ui_->customerCombo, SIGNAL(activated(int)), this, SLOT(SetEdit(int)));
	connect(ui_->modifyButton, SIGNAL(clicked()), this, SLOT(Modify()));
	connect(ui_->returnButton, SIGNAL(clicked()), this, SLOT(close()));
	ui_->roomEdit->setEnabled(false);
	ui_->dayEdit->setEnabled(false);
	for (int i = 0; i < list.GetLength(); i++)
	{
		QString name = "";
		QString ID = "";
		int number = 0;
		int day = 0;
		list_.GetCustomer(i, name, ID, number, day);
		QString item;
		item.append(name);
		item.append(" ");
		item.append(ID);
		item.append(QString(" %1").arg(number, 4, 10, QLatin1Char(' ')));
		item.append(QString(" %1").arg(day, 2, 10, QLatin1Char(' ')));
		ui_->customerCombo->addItem(item);
	}
	ui_->customerCombo->setCurrentIndex(-1);
}
ModifyCustomerDialog::~ModifyCustomerDialog()
{
	delete ui_;
}
void ModifyCustomerDialog::SetEdit(int index)
{
	QString name = "";
	QString ID = "";
	int number = 0;
	int day = 0;
	list_.GetCustomer(index, name, ID, number, day);
	ui_->nameEdit->setText(name);
	ui_->IDEdit->setText(ID);
	ui_->roomEdit->setText(QString("%1").arg(number));
	ui_->dayEdit->setText(QString("%1").arg(day));
}
void ModifyCustomerDialog::Modify()
{
	list_.SetCustomer(ui_->customerCombo->currentIndex(), ui_->nameEdit->text(), ui_->IDEdit->text(), ui_->roomEdit->text().toInt(), ui_->dayEdit->text().toInt());
	QString itemText;
	itemText.append(ui_->nameEdit->text());
	itemText.append(" ");
	itemText.append(ui_->IDEdit->text());
	itemText.append(QString(" %1").arg(ui_->roomEdit->text().toInt(), 4, 10, QLatin1Char(' ')));
	itemText.append(QString(" %1").arg(ui_->dayEdit->text().toInt(), 2, 10, QLatin1Char(' ')));
	ui_->customerCombo->setItemText(ui_->customerCombo->currentIndex(), itemText);
	QMessageBox box(QMessageBox::Information, "成功", "操作成功。", QMessageBox::NoButton, this);
	box.setWindowIcon(QIcon(":/HotelManagingSystem/Information Icon.ico"));
	box.setIconPixmap(QPixmap(":/HotelManagingSystem/Information Icon.ico").scaled(32, 32));
	box.setFont(QFont("宋体", 12));
	box.addButton("确定", QMessageBox::AcceptRole)->setFont(QFont("宋体", 12));
	box.exec();
}