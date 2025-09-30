#include "eospatchform.h"
#include "ui_eospatchform.h"

EosPatchForm::EosPatchForm(EosForm *eosForm, QWidget *parent) :
		QWidget(parent),
		ui(new Ui::EosPatchForm) {
	ui->setupUi(this);

	for (int i = 0; i < 256; i++) {
		eosForm->board->queryPatchData(i);
	}
}

EosPatchForm::~EosPatchForm() {
	delete ui;
}
