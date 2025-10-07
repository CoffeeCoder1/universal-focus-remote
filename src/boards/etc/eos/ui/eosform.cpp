#include "eosform.h"
#include "eoskeypadform.h"
#include "eospatchform.h"
#include "eossyntaxhighlighter.h"
#include "ui_eosform.h"

#include <QTabBar>
#include <QTabWidget>

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

	// Set up the tab widget
	QTabWidget *tabArea = new QTabWidget();
	tabArea->setMovable(true);
	ui->verticalLayout->insertWidget(1, tabArea);

	QWidget *keypadWidget = new EosKeypadForm(this);
	tabArea->addTab(keypadWidget, "Keypad");

	QWidget *patchWidget = new EosPatchForm(this);
	tabArea->addTab(patchWidget, "Patch");
}

EosForm::~EosForm() {
	delete ui;
}
