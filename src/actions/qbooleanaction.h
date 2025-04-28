#pragma once

#include <QKeySequence>
#include <QObject>

class QBooleanAction : public QObject {
	Q_OBJECT

private:
	bool value;
	const QKeySequence *shortcutSequence;

public:
	explicit QBooleanAction(QObject *parent = nullptr);
	bool eventFilter(QObject *object, QEvent *event);
	void setShortcut(const QKeySequence *keySequence);

public slots:
	void setValue(bool value);

signals:
	void valueChanged(bool value);
};
