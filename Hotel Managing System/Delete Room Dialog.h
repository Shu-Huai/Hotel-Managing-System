#pragma once
#include <QDialog>
#include "Room List.h"
#include "ui_Delete Room Dialog.h"
class DeleteRoomDialog : public QDialog
{
	Q_OBJECT
public:
	DeleteRoomDialog(RoomList& list, QWidget* parent = NULL);
	~DeleteRoomDialog();
public slots:
	void DeleteRoom();
	void SelectAll();
	void SelectNone();
	void SelectReverse();
private:
	Ui::DeleteRoomDialog *ui_;
	RoomList& list_;
};