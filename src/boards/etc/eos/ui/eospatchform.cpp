#include "eospatchform.h"
#include "ui_eospatchform.h"

EosPatchForm::EosPatchForm(EosForm *eosForm, QWidget *parent) :
		QWidget(parent),
		ui(new Ui::EosPatchForm) {
	ui->setupUi(this);
}

EosPatchForm::~EosPatchForm() {
	delete ui;
}
