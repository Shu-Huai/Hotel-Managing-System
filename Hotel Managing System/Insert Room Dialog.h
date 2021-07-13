#pragma once
#include <QDialog>
#include "Room List.h"
#include "ui_Insert Room Dialog.h"
class InsertRoomDialog : public QDialog
{
	Q_OBJECT
public:
	friend class InsertDialog;
	InsertRoomDialog(RoomList& list_, QWidget* parent = NULL);
	~InsertRoomDialog();
public slots:
	void InsertRoom();
	void ClearEdit(bool flag = true);
private:
	Ui::InsertRoomDialog ui_;
	RoomList &list_;
};