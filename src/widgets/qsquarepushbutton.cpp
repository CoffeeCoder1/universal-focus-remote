#include "qsquarepushbutton.h"

QSquarePushButton::QSquarePushButton(QWidget *parent) :
		QPushButton{ parent } {
	QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
	sizePolicy.setHeightForWidth(true);
	setSizePolicy(sizePolicy);
}

int QSquarePushButton::heightForWidth(int w) const {
	return w;
};
