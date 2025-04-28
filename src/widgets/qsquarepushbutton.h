#pragma once

#include <QPushButton>
#include <QWidget>

class QSquarePushButton : public QPushButton {
	Q_OBJECT

public:
	explicit QSquarePushButton(QWidget *parent = nullptr);

	virtual int heightForWidth(int w) const;
};
