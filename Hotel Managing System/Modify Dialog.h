#pragma once
#include "Customer List.h"
#include "Modify Customer Dialog.h"
#include "Modify Room Dialog.h"
#include "Room List.h"
#include "ui_Modify Dialog.h"
class ModifyDialog : public QDialog
{
	Q_OBJECT
public:
	ModifyDialog(CustomerList& customerList_, RoomList& roomList_, QWidget* parent = NULL);
	~ModifyDialog();
public slots:
	void ModifytRoom();
	void ModifyCustomer();
private:
	Ui::ModifyDialog *ui_;
	ModifyCustomerDialog* modifyCustomerDialog_;
	ModifyRoomDialog* modifyRoomDialog_;
	CustomerList& customerList_;
	RoomList& roomList_;
};