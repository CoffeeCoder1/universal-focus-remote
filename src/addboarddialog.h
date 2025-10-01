#pragma once

#include "boards/etc/eos/eossettings.h"
#include <QDialog>

namespace Ui {
class AddBoardDialog;
}

class AddBoardDialog : public QDialog {
	Q_OBJECT

public:
	explicit AddBoardDialog(QWidget *parent = nullptr);
	~AddBoardDialog();

signals:
	void boardCreated(EosSettings *boardSettings);

private:
	Ui::AddBoardDialog *ui;
	void onAccepted();
};
