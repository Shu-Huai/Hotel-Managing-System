#pragma once
#include <QtWidgets/QMainWindow>
#include <QFile>
#include <QTextStream>
#include "ui_Hotel Managing System.h"
#include "Insert Dialog.h"
#include "Room List.h"
class HotelManagingSystem : public QMainWindow
{
	Q_OBJECT
public:
	HotelManagingSystem(QWidget* parent = Q_NULLPTR);
	void Exit();
public slots:
	void Insert();
private:
	Ui::HotelManagementClass ui_;
	InsertDialog* insertDialog_;
	RoomList list_;
};