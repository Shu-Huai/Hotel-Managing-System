#pragma once
#include <QDialog>
#include "ui_Insert Dialog.h"
#include "Insert Room Dialog.h"
class InsertDialog : public QDialog
{
	friend class HotelManagingSystem;
	Q_OBJECT
public:
	InsertDialog(QWidget* parent = NULL);
	~InsertDialog();
public slots:
	void InsertRoom();
	void InsertCustomer();
protected:
	RoomList list_;
private:
	Ui::InsertDialog ui_;
	InsertRoomDialog* insertRoomDialog_;
};