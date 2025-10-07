#include "qboardtabarea.h"
#include "qsquarepushbutton.h"

#include <QFrame>
#include <QSpacerItem>
#include <QStackedLayout>
#include <QToolButton>

QBoardTabArea::QBoardTabArea(QWidget *parent) :
		QWidget(parent) {
	QStackedLayout *layout = new QStackedLayout();
	setLayout(layout);

	// Set up the tab widget
	tabWidget = new QTabWidget(this);
	layout->addWidget(tabWidget);
	tabWidget->setMovable(true);

	// Set up the tab list
	tabList = new QList<tab>();

	// Set up the new tab button
	QToolButton *newTabCornerButton = new QToolButton(tabWidget);
	tabWidget->setCornerWidget(newTabCornerButton);
	newTabCornerButton->setText("+");
	connect(newTabCornerButton, &QToolButton::pressed, this, &QBoardTabArea::showTabDialog);

	// Set up a new tab button that shows when no tabs are present
	QFrame *centerButton = new QFrame(this);
	layout->insertWidget(0, centerButton);
	QGridLayout *centerButtonLayout = new QGridLayout();
	centerButton->setLayout(centerButtonLayout);

	QSpacerItem *leftSpacer = new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
	centerButtonLayout->addItem(leftSpacer, 1, 0);
	QSpacerItem *rightSpacer = new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
	centerButtonLayout->addItem(rightSpacer, 1, 2);
	QSpacerItem *topSpacer = new QSpacerItem(0, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
	centerButtonLayout->addItem(topSpacer, 0, 1);
	QSpacerItem *bottomSpacer = new QSpacerItem(0, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
	centerButtonLayout->addItem(bottomSpacer, 2, 1);

	QSquarePushButton *newTabButton = new QSquarePushButton(centerButton);
	centerButtonLayout->addWidget(newTabButton, 1, 1);
	newTabButton->setText("+");
	newTabButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	newTabButton->setMinimumSize(QSize(40, 40));
	connect(newTabButton, &QToolButton::pressed, this, &QBoardTabArea::showTabDialog);

	layout->setCurrentIndex(0);
	connect(tabWidget, &QTabWidget::currentChanged, this, [=](int index) {
		if (index == -1) {
			// No tabs present, show the new tab button
			layout->setCurrentIndex(0);
		} else {
			layout->setCurrentIndex(1);
		}
	});

	// Setup double click to remove tabs
	connect(tabWidget, &QTabWidget::tabBarDoubleClicked, this, [=](int index) {
		tabWidget->removeTab(index);
	});
}

void QBoardTabArea::addTabToList(const QString name, std::function<QWidget *()> tabCreatedCallback) {
	tab newTab;
	newTab.name = name;
	newTab.initializer = tabCreatedCallback;

	tabList->append(newTab);
}

void QBoardTabArea::showTabDialog() {
	QNewTabDialog *newTabDialog = new QNewTabDialog(this);
	newTabDialog->setAttribute(Qt::WA_DeleteOnClose);
	newTabDialog->addTabsFromList(tabList);

	connect(newTabDialog, &QNewTabDialog::tabSelected, this, [=](tab newTab) {
		tabWidget->addTab(newTab.initializer(), newTab.name);
	});

	newTabDialog->show();
}
