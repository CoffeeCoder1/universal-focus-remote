#pragma once

#include <QKeySequence>
#include <QObject>
#include <QPushButton>

class QBooleanAction : public QObject {
	Q_OBJECT

private:
	bool value;
	const QKeySequence *shortcutSequence;

public:
	explicit QBooleanAction(QObject *parent = nullptr);
	bool eventFilter(QObject *object, QEvent *event);
	void setShortcut(const QKeySequence *keySequence);
	/**
	 * @brief Binds this boolean action to a button.
	 * @param button The button to bind.
	 */
	void setupActionButton(QPushButton *button);

public slots:
	void setValue(bool value);

signals:
	void valueChanged(bool value);
};
