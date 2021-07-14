#pragma once
#include <QDialog>
#include "Room List.h"
#include "ui_Modify Room Dialog.h"
class ModifyRoomDialog : public QDialog
{
	Q_OBJECT
public:
	ModifyRoomDialog(RoomList& list, QWidget* parent = NULL);
	~ModifyRoomDialog();
public slots:
	void SetEdit(int index);
	void Modify();
private:
	Ui::ModifyRoomDialog *ui_;
	RoomList& list_;
};