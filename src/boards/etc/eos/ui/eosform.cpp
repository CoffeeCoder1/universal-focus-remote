#include "eosform.h"
#include "eossyntaxhighlighter.h"
#include "ui_eosform.h"

EosForm::EosForm(ETCEos* board, QWidget *parent) : QWidget(parent), ui(new Ui::EosForm) {
	this->board = board;

	ui->setupUi(this);

	// Set up the command line
	QFontMetrics metrics(ui->commandLine->font());
	int lineHeight = metrics.lineSpacing();
	ui->commandLine->setFixedHeight(lineHeight + 10);
	ui->commandLine->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	connect(board, &ETCEos::userCommandLineChanged, ui->commandLine, [=](QString text) { ui->commandLine->setText(text.replace('#', "♦")); });
	new EosSyntaxHighlighter(ui->commandLine->document());

	// Bind actions to the buttons
	setupActionButton(ui->key0, board->keyAction0);
	setupActionButton(ui->key1, board->keyAction1);
	setupActionButton(ui->key2, board->keyAction2);
	setupActionButton(ui->key3, board->keyAction3);
	setupActionButton(ui->key4, board->keyAction4);
	setupActionButton(ui->key5, board->keyAction5);
	setupActionButton(ui->key6, board->keyAction6);
	setupActionButton(ui->key7, board->keyAction7);
	setupActionButton(ui->key8, board->keyAction8);
	setupActionButton(ui->key9, board->keyAction9);
	setupActionButton(ui->keyAt, board->keyActionAt);
	setupActionButton(ui->keyClear, board->keyActionClear);
	setupActionButton(ui->keyEnter, board->keyActionEnter);
	setupActionButton(ui->keyFull, board->keyActionFull);
	setupActionButton(ui->keyHome, board->keyActionHome);
	setupActionButton(ui->keyLast, board->keyActionLast);
	setupActionButton(ui->keyLevel, board->keyActionLevel);
	setupActionButton(ui->keyMark, board->keyActionMark);
	setupActionButton(ui->keyMinus, board->keyActionMinus);
	setupActionButton(ui->keyNext, board->keyActionNext);
	setupActionButton(ui->keyOut, board->keyActionOut);
	setupActionButton(ui->keyPercentMinus, board->keyActionPercentMinus);
	setupActionButton(ui->keyPercentPlus, board->keyActionPercentPlus);
	setupActionButton(ui->keyPlus, board->keyActionPlus);
	setupActionButton(ui->keyQOnly, board->keyActionQOnly);
	setupActionButton(ui->keyRemDim, board->keyActionRemDim);
	setupActionButton(ui->keySelectActive, board->keyActionSelectActive);
	setupActionButton(ui->keySelectLast, board->keyActionSelectLast);
	setupActionButton(ui->keySelectManual, board->keyActionSelectManual);
	setupActionButton(ui->keySneak, board->keyActionSneak);
	setupActionButton(ui->keySlash, board->keyActionSlash);
	setupActionButton(ui->keyTrace, board->keyActionTrace);
}

EosForm::~EosForm() {
	delete ui;
}

void EosForm::setupActionButton(QPushButton *button, QBooleanAction *action) {
	connect(button, &QAbstractButton::pressed, action, [=]() { action->setValue(true); });
	connect(button, &QAbstractButton::released, action, [=]() { action->setValue(false); });
	connect(action, &QBooleanAction::valueChanged, button, [=](bool value) { button->setDown(value); });
}
