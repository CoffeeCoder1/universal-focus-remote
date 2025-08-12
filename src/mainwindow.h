#pragma once

#include "boards/etc/eos/ui/eosform.h"
#include "boardselector.h"

#include <QFile>
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
	EosForm *boardForm;
	BoardSelector *boardSelector;

	bool loadBoard(QString fileName);
	bool saveBoard(EosSettings *boardSettings, QString fileName) const;

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;

public slots:
	void setBoardForm(EosForm *boardForm);

private:
	Ui::MainWindow *ui;
};
