#include "qbooleanaction.h"

#include <QApplication>
#include <QKeyEvent>

QBooleanAction::QBooleanAction(QObject *parent) :
		QObject{ parent } {
	QApplication::instance()->installEventFilter(this);
}

void QBooleanAction::setShortcut(const QKeySequence *keySequence) {
	shortcutSequence = keySequence;
};

bool QBooleanAction::eventFilter(QObject *object, QEvent *event) {
	if (shortcutSequence) {
		if (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease) {
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

			if (shortcutSequence->matches(keyEvent->key()) == QKeySequence::ExactMatch) {
				bool newValue = event->type() == QInputEvent::KeyPress;
				if (newValue != value) {
					setValue(newValue);
				}
			}
		}
	}
	return false;
}

void QBooleanAction::setValue(bool value) {
	this->value = value;

	emit valueChanged(value);
}

void QBooleanAction::setupActionButton(QPushButton *button) {
	connect(button, &QAbstractButton::pressed, this, [=]() { this->setValue(true); });
	connect(button, &QAbstractButton::released, this, [=]() { this->setValue(false); });
	connect(this, &QBooleanAction::valueChanged, button, [=](bool value) { button->setDown(value); });
}
