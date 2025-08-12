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

	void addBoard(EosSettings *boardSettings);

signals:
	void boardSelected(EosForm *boardForm);

private slots:
	void buttonClicked(EosSettings *boardSettings);

private:
	Ui::BoardSelector *ui;
};
