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

void BoardSelector::on_pushButton_clicked() {
	ETCEos *board = new ETCEos();
	emit boardSelected(new EosForm(board));
}
