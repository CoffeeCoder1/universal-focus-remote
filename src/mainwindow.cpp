#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "boards/etc/eos/eossettings.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QKeyEvent>
#include <QMessageBox>
#include <QStyleFactory>

MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

	boardSelector = new BoardSelector();
	connect(boardSelector, &BoardSelector::boardSelected, this, &MainWindow::setBoardForm);
	setCentralWidget(boardSelector);

	loadBoard(QStringLiteral("save.json"));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setBoardForm(EosForm *boardForm) {
	this->boardForm = boardForm;
	setCentralWidget(boardForm);
}

bool MainWindow::loadBoard(QString fileName) {
	QFile file(fileName);

	if (!file.open(QIODevice::ReadOnly)) {
		qWarning("Couldn't open board file.");
		return false;
	}

	QByteArray boardData = file.readAll();

	QJsonDocument loadDoc(QJsonDocument::fromJson(boardData));

	EosSettings boardSettingsObject;
	boardSettingsObject.read(loadDoc.object());

	QTextStream(stdout) << "Loaded board "
						<< loadDoc["name"].toString();
	return true;
}

bool MainWindow::saveBoard(QString fileName) const {
	QFile file(fileName);

	if (!file.open(QIODevice::WriteOnly)) {
		qWarning("Couldn't open board file.");
		return false;
	}

	QJsonObject boardObject;
	EosSettings boardSettingsObject;
	boardSettingsObject.write(boardObject);
	file.write(QJsonDocument(boardObject).toJson());

	return true;
}
