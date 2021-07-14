#include "Modify Dialog.h"
ModifyDialog::ModifyDialog(CustomerList& customerList, RoomList& roomList, QWidget* parent)
	: QDialog(parent), modifyCustomerDialog_(NULL), modifyRoomDialog_(NULL), customerList_(customerList), roomList_(roomList)
{
	ui_ = new Ui::ModifyDialog;
	ui_->setupUi(this);
	connect(ui_->customerButton, SIGNAL(clicked()), this, SLOT(ModifyCustomer()));
	connect(ui_->roomButton, SIGNAL(clicked()), this, SLOT(ModifytRoom()));
	connect(ui_->returnButton, SIGNAL(clicked()), this, SLOT(close()));
}
ModifyDialog::~ModifyDialog()
{
	delete ui_;
}
void ModifyDialog::ModifyCustomer()
{
	modifyCustomerDialog_ = new ModifyCustomerDialog(customerList_);
	modifyCustomerDialog_->setWindowIcon(QIcon(":/HotelManagingSystem/Hotel Managing System Window Icon.ico"));
	modifyCustomerDialog_->setWindowTitle("修改客人");
	modifyCustomerDialog_->exec();
	delete modifyCustomerDialog_;
}
void ModifyDialog::ModifytRoom()
{
	modifyRoomDialog_ = new ModifyRoomDialog(roomList_);
	modifyRoomDialog_->setWindowIcon(QIcon(":/HotelManagingSystem/Hotel Managing System Window Icon.ico"));
	modifyRoomDialog_->setWindowTitle("修改房间");
	modifyRoomDialog_->exec();
	delete modifyRoomDialog_;
}