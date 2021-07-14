#pragma once
#include "Insert Customer Dialog.h"
#include "Insert Room Dialog.h"
#include "ui_Insert Dialog.h"
class InsertDialog : public QDialog
{
	Q_OBJECT
public:
	InsertDialog(CustomerList& customerList_, RoomList& roomList_, QWidget* parent = NULL);
	~InsertDialog();
public slots:
	void InsertCustomer();
	void InsertRoom();
private:
	Ui::InsertDialog *ui_;
	InsertRoomDialog* insertRoomDialog_;
	InsertCustomerDialog* insertCustomerDialog_;
	CustomerList& customerList_;
	RoomList& roomList_;
};