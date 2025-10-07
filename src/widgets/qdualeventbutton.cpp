#include "qdualeventbutton.h"

QDualEventButton::QDualEventButton(QWidget *parent) :
		QPushButton(parent) {
}

void QDualEventButton::mousePressEvent(QMouseEvent *e) {
	if (e->button() == Qt::RightButton)
		emit secondaryClick();

	// Forward the click event to the underlying QPushButton
	QPushButton::mousePressEvent(e);
}
