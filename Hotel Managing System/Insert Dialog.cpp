#include "Insert Dialog.h"
InsertDialog::InsertDialog(QWidget* parent) : QDialog(parent), insertRoomDialog_(NULL)
{
	ui_.setupUi(this);
	connect(ui_.RoomPush, SIGNAL(clicked()), this, SLOT(InsertRoom()));
	connect(ui_.CustomerPush, SIGNAL(clicked()), this, SLOT(InsertCustomer()));
	connect(ui_.ReturnPush, SIGNAL(clicked()), this, SLOT(close()));
}
InsertDialog::~InsertDialog()
{
}
void InsertDialog::InsertRoom()
{
	insertRoomDialog_ = new InsertRoomDialog;
	insertRoomDialog_->list_ = list_;
	insertRoomDialog_->exec();
	list_ = insertRoomDialog_->list_;
	delete insertRoomDialog_;
}
void InsertDialog::InsertCustomer()
{

}