#pragma once

#include <QDialog>

namespace Ui {
class QNewTabDialog;
}

struct tab {
	QString name;
	std::function<QWidget *()> initializer;
};

class QNewTabDialog : public QDialog {
	Q_OBJECT

public:
	explicit QNewTabDialog(QWidget *parent = nullptr);
	~QNewTabDialog();

	void addTabsFromList(QList<tab> *tabList);

signals:
	void tabSelected(tab newTab);

private:
	Ui::QNewTabDialog *ui;
};
