#include "boardselector.h"
#include "ui_boardselector.h"

BoardSelector::BoardSelector(QWidget *parent) :
		QWidget(parent),
		ui(new Ui::BoardSelector) {
	ui->setupUi(this);

	ui->scrollArea->setWidgetResizable(true);
	ui->scrollArea->setWidget(ui->scrollFrame);

	addBoardDialog = new AddBoardDialog();
	connect(ui->addBoardButton, &QPushButton::clicked, addBoardDialog, &AddBoardDialog::open);
	connect(addBoardDialog, &AddBoardDialog::boardCreated, this, [=](EosSettings *board) { this->addBoard(board); emit boardCreated(board); });
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
	ui->boardList->layout()->addWidget(button);

	// Set up the button
	button->setText(boardSettings->getName());

	// Connect the button clicked signal
	connect(button, &QPushButton::clicked, this, [=](bool value) { buttonClicked(boardSettings); });
}
