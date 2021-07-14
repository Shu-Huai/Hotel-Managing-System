#pragma once
#include <QDialog>
#include "Customer List.h"
#include "Room List.h"
#include "ui_Insert Customer Dialog.h"
class InsertCustomerDialog : public QDialog
{
	Q_OBJECT
public:
	InsertCustomerDialog(CustomerList& customerList, RoomList& roomList, QWidget* parent = NULL);
	~InsertCustomerDialog();
public slots:
	void InsertCustomer();
	void ClearEdit(bool isButtonPushed = true);
private:
	Ui::InsertCustomerDialog *ui_;
	CustomerList& customerList_;
	RoomList& roomList_;
};