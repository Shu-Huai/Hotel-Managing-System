#pragma once
#include <QtWidgets/QMainWindow>
#include <QFile>
#include <QTextStream>
#include "ui_Hotel Managing System.h"
#include "Insert Dialog.h"
#include "Delete Room Dialog.h"
#include "Check Out Dialog.h"
class HotelManagingSystem : public QMainWindow
{
	Q_OBJECT
public:
	HotelManagingSystem(QWidget* parent = NULL);
	~HotelManagingSystem();
	void Exit();
public slots:
	void Insert();
	void DeleteRoom();
	void CheckOut();
private:
	Ui::HotelManagementClass *ui_;
	InsertDialog* insertDialog_;
	DeleteRoomDialog* deleteRoomDialog_;
	CheckOutDialog* checkOutDialog_;
	CustomerList customerList_;
	RoomList roomList_;
};