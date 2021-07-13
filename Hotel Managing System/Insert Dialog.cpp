#include "Insert Dialog.h"
InsertDialog::InsertDialog(CustomerList& customerList, RoomList& roomList, QWidget* parent)
	: QDialog(parent), insertRoomDialog_(NULL), insertCustomerDialog_(NULL), customerList_(customerList), roomList_(roomList)
{
	ui_ = new Ui::InsertDialog;
	ui_->setupUi(this);
	connect(ui_->roomButton, SIGNAL(clicked()), this, SLOT(InsertRoom()));
	connect(ui_->customerButton, SIGNAL(clicked()), this, SLOT(InsertCustomer()));
	connect(ui_->returnButton, SIGNAL(clicked()), this, SLOT(close()));
}
InsertDialog::~InsertDialog()
{
	delete ui_;
}
void InsertDialog::InsertRoom()
{
	insertRoomDialog_ = new InsertRoomDialog(roomList_);
	insertRoomDialog_->exec();
	delete insertRoomDialog_;
}
void InsertDialog::InsertCustomer()
{
	insertCustomerDialog_ = new InsertCustomerDialog(customerList_, roomList_);
	insertCustomerDialog_->exec();
	delete insertCustomerDialog_;
}