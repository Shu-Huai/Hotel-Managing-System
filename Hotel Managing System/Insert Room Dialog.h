#pragma once
#include <QDialog>
#include "Room List.h"
#include "ui_Insert Room Dialog.h"
class InsertRoomDialog : public QDialog
{
	friend class InsertDialog;
	Q_OBJECT
public:
	InsertRoomDialog(QWidget* parent = NULL);
	~InsertRoomDialog();
protected:
	RoomList list_;
private:
	Ui::InsertRoomDialog ui_;
public slots:
	void on_btnConfirmPush_clicked();
	void on_btnClearPush_clicked(bool flag = 0);
};