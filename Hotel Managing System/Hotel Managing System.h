#pragma once
#include <QtWidgets/QMainWindow>
#include <QFile>
#include <QTextStream>
#include "ui_Hotel Managing System.h"
#include "Insert Dialog.h"
class HotelManagingSystem : public QMainWindow
{
	Q_OBJECT
public:
	HotelManagingSystem(QWidget* parent = Q_NULLPTR);
	~HotelManagingSystem();
	void Exit();
public slots:
	void Insert();
private:
	Ui::HotelManagementClass *ui_;
	InsertDialog* insertDialog_;
	CustomerList customerList_;
	RoomList roomList_;
};