#pragma once
#include <QDialog>
#include "Room List.h"
#include "ui_Search Room Dialog.h"
class SearchRoomDialog : public QDialog
{
	Q_OBJECT
public:
	SearchRoomDialog(RoomList& list, QWidget* parent = NULL);
	~SearchRoomDialog();
private:
	Ui::SearchRoomDialog* ui_;
	RoomList& list_;
};