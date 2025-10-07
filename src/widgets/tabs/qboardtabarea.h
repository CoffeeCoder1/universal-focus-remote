#pragma once

#include "qnewtabdialog.h"

#include <QTabWidget>

class QBoardTabArea : public QTabWidget {
	Q_OBJECT

public:
	explicit QBoardTabArea(QWidget *parent = 0);

	void addTabToList(const QString name, std::function<QWidget *()> tabCreatedCallback);

private:
	QList<tab> *tabList;
	void showTabDialog();
};
