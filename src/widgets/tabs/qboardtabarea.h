#pragma once

#include "qnewtabdialog.h"

#include <QTabWidget>

class QBoardTabArea : public QWidget {
	Q_OBJECT

public:
	explicit QBoardTabArea(QWidget *parent = 0);

	void addTabToList(const QString name, std::function<QWidget *()> tabCreatedCallback);

private:
	QTabWidget *tabWidget;
	QList<tab> *tabList;
	void showTabDialog();
};
