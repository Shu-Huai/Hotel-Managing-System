#include <QTranslator.h>
#include <QtWidgets/QApplication>
#include "Hotel Managing System.h"
int main(int argc, char* argv[])
{
	QApplication application(argc, argv);
	QTranslator translator;
	if (translator.load(":/HotelManagingSystem/qt_zh_CN.qm"))
	{
		application.installTranslator(&translator);
	}
	HotelManagingSystem mainWindow;
	mainWindow.setWindowIcon(QIcon(":/HotelManagingSystem/Hotel Managing System Window Icon.ico"));
	mainWindow.setWindowTitle(QString("酒店管理系统"));
	mainWindow.show();
	int result = application.exec();
	mainWindow.Exit();
	return result;
}