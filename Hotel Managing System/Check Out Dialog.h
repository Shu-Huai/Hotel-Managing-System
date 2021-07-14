#pragma once
#include <QDialog>
#include "Customer List.h"
#include "Room List.h"
#include "ui_Check Out Dialog.h"
class CheckOutDialog : public QDialog
{
	Q_OBJECT
public:
	CheckOutDialog(CustomerList& customerList, RoomList& roomList, QWidget* parent = NULL);
	~CheckOutDialog();
public slots:
	void CheckOut();
	void SelectAll();
	void SelectNone();
	void SelectReverse();
private:
	Ui::CheckOutDialog* ui_;
	CustomerList& customerList_;
	RoomList& roomList_;
};