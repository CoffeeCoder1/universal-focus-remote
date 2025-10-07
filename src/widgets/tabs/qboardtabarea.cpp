#include "qboardtabarea.h"

#include <QToolButton>

QBoardTabArea::QBoardTabArea(QWidget *parent) :
		QTabWidget(parent) {
	// Set up the tab widget
	setMovable(true);

	// Add a blank tab (needed because the add tab button doesn't show up without any tabs)
	addTab(new QWidget(), "Blank");

	// Set up the tab list
	tabList = new QList<tab>();

	// Set up the new tab button
	QToolButton *newTabButton = new QToolButton();
	setCornerWidget(newTabButton);
	newTabButton->setText("+");
	connect(newTabButton, &QToolButton::pressed, this, &QBoardTabArea::showTabDialog);
}

void QBoardTabArea::addTabToList(const QString name, std::function<QWidget *()> tabCreatedCallback) {
	tab newTab;
	newTab.name = name;
	newTab.initializer = tabCreatedCallback;

	tabList->append(newTab);
}

void QBoardTabArea::showTabDialog() {
	QNewTabDialog *newTabDialog = new QNewTabDialog();
	newTabDialog->setAttribute(Qt::WA_DeleteOnClose);
	newTabDialog->addTabsFromList(tabList);

	connect(newTabDialog, &QNewTabDialog::tabSelected, this, [=](tab newTab) {
		addTab(newTab.initializer(), newTab.name);
	});

	newTabDialog->show();
}
