#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	QFile stylesheetFile(":style/style.qss");

	if (!stylesheetFile.exists()) {
		printf("Unable to set stylesheet, file not found\n");
	} else {
		stylesheetFile.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&stylesheetFile);
		qApp->setStyleSheet(ts.readAll());
	}

	MainWindow w;
	w.show();

	return a.exec();
}
