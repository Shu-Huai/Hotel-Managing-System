#include <fstream>
#include <QtWidgets/QApplication>
#include "Hotel Managing System.h"
int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	HotelManagingSystem w;
	w.show();
	return a.exec();
}