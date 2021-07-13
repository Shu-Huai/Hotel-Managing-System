#include <QTranslator.h>
#include <QtWidgets/QApplication>
#include "Hotel Managing System.h"
int main(int argc, char* argv[])
{
	QApplication application(argc, argv);
	QTranslator translator;
	if (translator.load(":/qt_zh_CN.qm"))
	{
		application.installTranslator(&translator);
	}
	HotelManagingSystem mainWindow;
	mainWindow.show();
	int result = application.exec();
	mainWindow.Exit();
	return result;
}