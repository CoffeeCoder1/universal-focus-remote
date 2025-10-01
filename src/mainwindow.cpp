#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "boards/etc/eos/eossettings.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QKeyEvent>
#include <QMessageBox>
#include <QStandardPaths>
#include <QStyleFactory>

MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

	boardSelector = new BoardSelector();
	connect(boardSelector, &BoardSelector::boardSelected, this, &MainWindow::setBoardForm);
	connect(boardSelector, &BoardSelector::boardCreated, this, &MainWindow::onBoardCreated);
	setCentralWidget(boardSelector);

	QString boardDirPath = QDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation))
								   .filePath("boards");

	boardDir = new QDir(boardDirPath);
	boardDir->mkpath(boardDirPath);

	QStringList boardFileNames = boardDir->entryList(QDir::Files | QDir::Readable);
	for (const QString &boardName : std::as_const(boardFileNames)) {
		loadBoard(boardDir->filePath(boardName));
	}
}

MainWindow::~MainWindow(){
	delete ui;
}

void MainWindow::setBoardForm(EosForm *boardForm) {
	this->boardForm = boardForm;
	setCentralWidget(boardForm);
}

bool MainWindow::loadBoard(QString filePath) {
	QFile file(filePath);

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
	connect(boardSettingsObject, &EosSettings::updated, this, [=]() { saveBoard(boardSettingsObject, filePath); });

	qDebug() << "Loaded board"
			 << loadDoc["name"].toString();
	return true;
}

bool MainWindow::saveBoard(EosSettings *boardSettings, QString fileName) const {
	QFile file(boardDir->filePath(fileName));

	if (!file.open(QIODevice::WriteOnly)) {
		qWarning("Couldn't open board file.");
		return false;
	}

	QJsonObject jsonObject;
	boardSettings->write(jsonObject);
	file.write(QJsonDocument(jsonObject).toJson());

	return true;
}

void MainWindow::onBoardCreated(EosSettings *boardSettings) {
	QString fileName = QUuid::createUuid().toString(QUuid::WithoutBraces) + ".json";

	// Save settings to disk
	saveBoard(boardSettings, fileName);

	// Save settings to disk when they change
	connect(boardSettings, &EosSettings::updated, this, [=]() { saveBoard(boardSettings, fileName); });
}
