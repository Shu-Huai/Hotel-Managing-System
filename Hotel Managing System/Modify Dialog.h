#pragma once
#include "Modify Customer Dialog.h"
#include "Modify Room Dialog.h"
#include "ui_Modify Dialog.h"
class ModifyDialog : public QDialog
{
	Q_OBJECT
public:
	ModifyDialog(CustomerList& customerList, RoomList& roomList, QWidget* parent = NULL);
	~ModifyDialog();
public slots:
	void ModifyRoom();
	void ModifyCustomer();
private:
	Ui::ModifyDialog *ui_;
	ModifyCustomerDialog* modifyCustomerDialog_;
	ModifyRoomDialog* modifyRoomDialog_;
	CustomerList& customerList_;
	RoomList& roomList_;
};