#pragma once

#include <QMouseEvent>
#include <QPushButton>
#include <QWidget>

class QDualEventButton : public QPushButton {
	Q_OBJECT

public:
	explicit QDualEventButton(QWidget *parent = 0);

private slots:
	void mousePressEvent(QMouseEvent *e);

signals:
	void secondaryClick();

public slots:
};
