#pragma once
#include <QDialog>
#include "ui_Insert Dialog.h"
#include "Insert Room Dialog.h"
class InsertDialog : public QDialog
{
	friend class HotelManagingSystem;
	Q_OBJECT
public:
	InsertDialog(RoomList& list, QWidget* parent = NULL);
	~InsertDialog();
public slots:
	void InsertRoom();
	void InsertCustomer();
private:
	Ui::InsertDialog ui_;
	InsertRoomDialog* insertRoomDialog_;
	RoomList& list_;
};