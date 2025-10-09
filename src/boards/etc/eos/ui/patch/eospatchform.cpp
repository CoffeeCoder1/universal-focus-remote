#include "eospatchform.h"
#include "qpatchdatamodel.h"
#include "ui_eospatchform.h"

#include <QLabel>
#include <QStandardItemModel>
#include <QVBoxLayout>

EosPatchForm::EosPatchForm(EosForm *eosForm, QWidget *parent) :
		QWidget(parent),
		ui(new Ui::EosPatchForm) {
	ui->setupUi(this);
	this->eosForm = eosForm;

	QPatchDataModel *patchModel = new QPatchDataModel();
	ui->tableView->setModel(patchModel);

	patchModel->setChannelData(eosForm->board->getChannelData());

	connect(eosForm->board, &ETCEos::patchUpdated, this, [=]() {
		patchModel->setChannelData(eosForm->board->getChannelData());
	});
}

EosPatchForm::~EosPatchForm() {
	delete ui;
}
