#include "Search Dialog.h"
SearchDialog::SearchDialog(CustomerList& customerList, RoomList& roomList, QWidget* parent)
	: QDialog(parent), searchCustomerDialog_(NULL), searchRoomDialog_(NULL), customerList_(customerList), roomList_(roomList)
{
	ui_ = new Ui::SearchDialog;
	ui_->setupUi(this);
	connect(ui_->customerButton, SIGNAL(clicked()), this, SLOT(SearchCustomer()));
	connect(ui_->roomButton, SIGNAL(clicked()), this, SLOT(SearchRoom()));
	connect(ui_->returnButton, SIGNAL(clicked()), this, SLOT(close()));
}
SearchDialog::~SearchDialog()
{
	delete ui_;
}
void SearchDialog::SearchCustomer()
{
	searchCustomerDialog_ = new SearchCustomerDialog(customerList_);
	searchCustomerDialog_->setWindowIcon(QIcon(":/HotelManagingSystem/Hotel Managing System Window Icon.ico"));
	searchCustomerDialog_->setWindowTitle("查找客人");
	searchCustomerDialog_->exec();
	delete searchCustomerDialog_;
}
void SearchDialog::SearchRoom()
{
	searchRoomDialog_ = new SearchRoomDialog(roomList_);
	searchRoomDialog_->setWindowIcon(QIcon(":/HotelManagingSystem/Hotel Managing System Window Icon.ico"));
	searchRoomDialog_->setWindowTitle("查找房间");
	searchRoomDialog_->exec();
	delete searchRoomDialog_;
}