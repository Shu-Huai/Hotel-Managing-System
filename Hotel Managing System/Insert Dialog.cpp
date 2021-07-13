#include "Insert Dialog.h"
InsertDialog::InsertDialog(RoomList& list, QWidget* parent) : QDialog(parent), insertRoomDialog_(NULL), list_(list)
{
	ui_.setupUi(this);
	connect(ui_.roomButton, SIGNAL(clicked()), this, SLOT(InsertRoom()));
	connect(ui_.customerButton, SIGNAL(clicked()), this, SLOT(InsertCustomer()));
	connect(ui_.returnButton, SIGNAL(clicked()), this, SLOT(close()));
}
InsertDialog::~InsertDialog()
{
}
void InsertDialog::InsertRoom()
{
	insertRoomDialog_ = new InsertRoomDialog(list_);
	insertRoomDialog_->exec();
	delete insertRoomDialog_;
}
void InsertDialog::InsertCustomer()
{

}