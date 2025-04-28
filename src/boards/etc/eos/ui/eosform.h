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
	/**
	 * @brief Binds a boolean action to a button.
	 * @param button The button to bind.
	 * @param action The action to bind.
	 */
	void setupActionButton(QPushButton *button, QBooleanAction *action);
};
