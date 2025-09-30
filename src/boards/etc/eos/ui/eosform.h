#pragma once

#include "../etceos.h"

#include <QAction>
#include <QPushButton>

namespace Ui {
class EosForm;
}

class EosForm : public QWidget {
	Q_OBJECT

public:
	explicit EosForm(ETCEos *board, QWidget *parent = nullptr);
	~EosForm();
	ETCEos *board;

private:
	Ui::EosForm *ui;
};
