#include "boardselector.h"
#include "ui_boardselector.h"

BoardSelector::BoardSelector(QWidget *parent) :
		QWidget(parent),
		ui(new Ui::BoardSelector) {
	ui->setupUi(this);
}

BoardSelector::~BoardSelector() {
	delete ui;
}

void BoardSelector::buttonClicked(EosSettings *boardSettings) {
	ETCEos *board = new ETCEos(boardSettings);
	emit boardSelected(new EosForm(board));
}

void BoardSelector::addBoard(EosSettings *boardSettings) {
	QPushButton *button = new QPushButton();
	ui->verticalLayout->addWidget(button);
	button->setText(boardSettings->getName());
	connect(button, &QPushButton::clicked, this, [=](bool value) { buttonClicked(boardSettings); });
}
