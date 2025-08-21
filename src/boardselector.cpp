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
	// Create a board button
	QPushButton *button = new QPushButton();
	ui->verticalLayout->addWidget(button);

	// Set up the button
	button->setText(boardSettings->getName());

	// Connect the button clicked signal
	connect(button, &QPushButton::clicked, this, [=](bool value) { buttonClicked(boardSettings); });
}
