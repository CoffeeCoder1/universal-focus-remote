#include "eospatchform.h"
#include "ui_eospatchform.h"

#include "../datatypes/eoschannel.h"

#include <QStandardItemModel>

EosPatchForm::EosPatchForm(EosForm *eosForm, QWidget *parent) :
		QWidget(parent),
		ui(new Ui::EosPatchForm) {
	ui->setupUi(this);

	this->eosForm = eosForm;

	QStandardItemModel *model = new QStandardItemModel(0, 4);

	QMap<QString, EosChannel *> channelData = eosForm->board->getChannelData();
	for (EosChannel *channel : std::as_const(channelData)) {
		QList<QStandardItem *> columns;
		columns.append(new QStandardItem(QString::number(channel->channelNumber)));
		columns.append(new QStandardItem(QString::number(channel->partNumber)));
		columns.append(new QStandardItem(QString::number(channel->address)));
		columns.append(new QStandardItem(channel->fixtureModel));
		model->appendRow(columns);
	}

	ui->tableView->setModel(model);
	ui->tableView->sortByColumn(0, Qt::SortOrder::AscendingOrder);
	ui->tableView->horizontalHeader()->setVisible(false);
}

EosPatchForm::~EosPatchForm() {
	delete ui;
}
