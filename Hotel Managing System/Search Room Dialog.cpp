#include "Search Room Dialog.h"
SearchRoomDialog::SearchRoomDialog(RoomList& list, QWidget* parent) : QDialog(parent), list_(list)
{
	ui_ = new Ui::SearchRoomDialog;
	ui_->setupUi(this);
}
SearchRoomDialog::~SearchRoomDialog()
{
	delete ui_;
}