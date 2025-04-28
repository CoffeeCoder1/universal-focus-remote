#pragma once

#include "boards/etc/eos/etceos.h"
#include "boards/etc/eos/ui/eosform.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	ETCEos *board;
	EosForm *boardForm;

private:
	Ui::MainWindow *ui;
};
