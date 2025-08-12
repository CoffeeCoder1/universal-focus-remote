#pragma once

#include "boards/etc/eos/ui/eosform.h"
#include <QWidget>

namespace Ui {
class BoardSelector;
}

class BoardSelector : public QWidget {
	Q_OBJECT

public:
	explicit BoardSelector(QWidget *parent = nullptr);
	~BoardSelector();

signals:
	void boardSelected(EosForm *boardForm);

private slots:
	void on_pushButton_clicked();

private:
	Ui::BoardSelector *ui;
};
