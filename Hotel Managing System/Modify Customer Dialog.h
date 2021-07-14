#pragma once
#include <QDialog>
#include "Customer List.h"
#include "ui_Modify Customer Dialog.h"
class ModifyCustomerDialog : public QDialog
{
	Q_OBJECT
public:
	ModifyCustomerDialog(CustomerList& list, QWidget* parent = NULL);
	~ModifyCustomerDialog();
public slots:
	void SetEdit(int index);
	void Modify();
private:
	Ui::ModifyCustomerDialog* ui_;
	CustomerList& list_;
};