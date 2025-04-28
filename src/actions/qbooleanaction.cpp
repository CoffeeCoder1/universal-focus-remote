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
