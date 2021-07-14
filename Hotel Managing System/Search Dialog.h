#pragma once
#include "Search Customer Dialog.h"
#include "Search Room Dialog.h"
#include "ui_Search Dialog.h"
class SearchDialog : public QDialog
{
	Q_OBJECT
public:
	SearchDialog(CustomerList& customerList, RoomList& roomList, QWidget* parent = NULL);
	~SearchDialog();
public slots:
	void SearchRoom();
	void SearchCustomer();
private:
	Ui::SearchDialog *ui_;
	SearchCustomerDialog* searchCustomerDialog_;
	SearchRoomDialog* searchRoomDialog_;
	CustomerList& customerList_;
	RoomList& roomList_;
};