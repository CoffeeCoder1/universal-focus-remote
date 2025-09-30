#include "eosform.h"
#include "eoskeypadform.h"
#include "eospatchform.h"
#include "eossyntaxhighlighter.h"
#include "ui_eosform.h"
#include <QMdiSubWindow>

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

	QWidget *keypadWidget = new EosKeypadForm(this);
	QMdiSubWindow *subWindow1 = new QMdiSubWindow;
	subWindow1->setWidget(keypadWidget);
	subWindow1->setAttribute(Qt::WA_DeleteOnClose);
	ui->mdiArea->addSubWindow(subWindow1);

	//QWidget *patchWidget = new EosPatchForm(this);
	//QMdiSubWindow *subWindow2 = new QMdiSubWindow;
	//subWindow2->setWidget(patchWidget);
	//subWindow2->setAttribute(Qt::WA_DeleteOnClose);
	//ui->mdiArea->addSubWindow(subWindow2);

	ui->mdiArea->tileSubWindows();
}

EosForm::~EosForm() {
	delete ui;
}
