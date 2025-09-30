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

	if (!loadBoard(QStringLiteral("save.json"))) {
		qWarning("Creating new board file");

		EosSettings *newBoard = new EosSettings();
		saveBoard(newBoard, QStringLiteral("save.json"));
		boardSelector->addBoard(newBoard);
	}
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

	EosSettings *boardSettingsObject = new EosSettings();
	boardSettingsObject->read(loadDoc.object());

	boardSelector->addBoard(boardSettingsObject);

	// Save settings to disk when they change
	connect(boardSettingsObject, &EosSettings::updated, this, [=]() { saveBoard(boardSettingsObject, fileName); });

	QTextStream(stdout) << "Loaded board "
						<< loadDoc["name"].toString();
	return true;
}

bool MainWindow::saveBoard(EosSettings *boardSettings, QString fileName) const {
	QFile file(fileName);

	if (!file.open(QIODevice::WriteOnly)) {
		qWarning("Couldn't open board file.");
		return false;
	}

	QJsonObject jsonObject;
	boardSettings->write(jsonObject);
	file.write(QJsonDocument(jsonObject).toJson());

	return true;
}
