#pragma once
#include <QDialog>
#include "Customer List.h"
#include "ui_Search Customer Dialog.h"
class SearchCustomerDialog : public QDialog
{
	Q_OBJECT
public:
	SearchCustomerDialog(CustomerList& list, QWidget* parent = NULL);
	~SearchCustomerDialog();
public slots:
	void SearchCustomer(QString text);
	void ClearEditor();
private:
	Ui::SearchCustomerDialog* ui_;
	CustomerList& list_;
};