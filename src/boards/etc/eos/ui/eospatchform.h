#pragma once

#include "eosform.h"
#include <QWidget>

namespace Ui {
class EosPatchForm;
}

class EosPatchForm : public QWidget {
	Q_OBJECT

public:
	explicit EosPatchForm(EosForm *eosForm, QWidget *parent = nullptr);
	~EosPatchForm();

private:
	Ui::EosPatchForm *ui;
};
