#include "addboarddialog.h"
#include "ui_addboarddialog.h"

AddBoardDialog::AddBoardDialog(QWidget *parent) :
		QDialog(parent),
		ui(new Ui::AddBoardDialog) {
	ui->setupUi(this);

	connect(this, &QDialog::accepted, this, &AddBoardDialog::onAccepted);
}

AddBoardDialog::~AddBoardDialog() {
	delete ui;
}

void AddBoardDialog::onAccepted() {
	EosSettings *settings = new EosSettings();

	settings->setName(ui->boardNameEdit->text());
	settings->setIp(ui->hostnameEdit->text());

	ui->boardNameEdit->clear();
	ui->hostnameEdit->clear();

	emit boardCreated(settings);
}
