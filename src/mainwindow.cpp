#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QKeyEvent>
#include <QMessageBox>
#include <QStyleFactory>

MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

	board = new ETCEos();

	boardForm = new EosForm(board);
	setCentralWidget(boardForm);
}

MainWindow::~MainWindow(){
    delete ui;
}
