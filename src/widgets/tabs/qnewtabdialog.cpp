#include "qnewtabdialog.h"
#include "ui_qnewtabdialog.h"

#include <QPushButton>

QNewTabDialog::QNewTabDialog(QWidget *parent) :
		QDialog(parent),
		ui(new Ui::QNewTabDialog) {
	ui->setupUi(this);
}

QNewTabDialog::~QNewTabDialog() {
	delete ui;
}

void QNewTabDialog::addTabsFromList(QList<tab> *tabList) {
	// Create a button for each tab
	for (const tab &newTab : std::as_const(*tabList)) {
		QPushButton *button = new QPushButton();
		button->setText(newTab.name);
		ui->tabList->addWidget(button);
		connect(button, &QPushButton::clicked, this, [=](bool checked) {
			emit tabSelected(newTab);
			close();
		});
	}
}
