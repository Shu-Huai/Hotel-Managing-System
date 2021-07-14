#include "Search Customer Dialog.h"
#include <QMessageBox>
SearchCustomerDialog::SearchCustomerDialog(CustomerList& list, QWidget* parent) : QDialog(parent), list_(list)
{
	ui_ = new Ui::SearchCustomerDialog;
	ui_->setupUi(this);
	connect(ui_->nameEdit, SIGNAL(textEdited(QString)), this, SLOT(SearchCustomer(QString)));
	connect(ui_->IDEdit, SIGNAL(textEdited(QString)), this, SLOT(SearchCustomer(QString)));
	connect(ui_->roomEdit, SIGNAL(textEdited(QString)), this, SLOT(SearchCustomer(QString)));
	connect(ui_->dayEdit, SIGNAL(textEdited(QString)), this, SLOT(SearchCustomer(QString)));
	connect(ui_->clearButton, SIGNAL(clicked()), this, SLOT(ClearEditor()));
	connect(ui_->returnButton, SIGNAL(clicked()), this, SLOT(close()));
	for (int i = 0; i < list_.GetLength(); i++)
	{
		QString item = "";
		item.append(list_.GetCustomerName(i));
		item.append(" ");
		item.append(list_.GetCustomerID(i));
		item.append(QString(" %1").arg(list_.GetCustomerRoomNumber(i), 4, 10, QLatin1Char(' ')));
		item.append(QString(" %1天").arg(list_.GetCustomerDay(i)));
		ui_->customerList->addItem(item);
	}
}
SearchCustomerDialog::~SearchCustomerDialog()
{
	delete ui_;
}
void SearchCustomerDialog::SearchCustomer(QString text)
{
	ui_->customerList->clear();
	QString name = ui_->nameEdit->text();
	QString ID = ui_->IDEdit->text();
	int room = ui_->roomEdit->text() == "" ? -1 : ui_->roomEdit->text().toInt();
	int day = ui_->dayEdit->text() == "" ? -1 : ui_->dayEdit->text().toInt();
	CustomerList& list = list_.SearchCustomer(name, ID, room, day);
	for (int i = 0; i < list.GetLength(); i++)
	{
		QString item = "";
		item.append(list.GetCustomerName(i));
		item.append(" ");
		item.append(list.GetCustomerID(i));
		item.append(QString(" %1").arg(list.GetCustomerRoomNumber(i), 4, 10, QLatin1Char(' ')));
		item.append(QString(" %1天").arg(list.GetCustomerDay(i)));
		ui_->customerList->addItem(item);
	}
	delete& list;
}
void SearchCustomerDialog::ClearEditor()
{
	if (ui_->nameEdit->text() != "" || ui_->IDEdit->text() != "" || ui_->roomEdit->text() != "" || ui_->dayEdit->text() != "")
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
		ui_->nameEdit->clear();
		ui_->IDEdit->clear();
		ui_->roomEdit->clear();
		ui_->dayEdit->clear();
	}
}