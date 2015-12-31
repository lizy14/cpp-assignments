#include "tempconverter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	tempConverter w;

	w.show();
	return a.exec();
}
