#pragma once

#include "../../../actions/qbooleanaction.h"
#include <QOsc>
#include <QObject>

class ETCEos : public QObject {
	Q_OBJECT

public:
	explicit ETCEos(QObject *parent = nullptr);

	QOscInterface *getInterface() { return &iface; };

	// Key actions
	QBooleanAction *keyAction0;
	QBooleanAction *keyAction1;
	QBooleanAction *keyAction2;
	QBooleanAction *keyAction3;
	QBooleanAction *keyAction4;
	QBooleanAction *keyAction5;
	QBooleanAction *keyAction6;
	QBooleanAction *keyAction7;
	QBooleanAction *keyAction8;
	QBooleanAction *keyAction9;
	QBooleanAction *keyActionAt;
	QBooleanAction *keyActionClear;
	QBooleanAction *keyActionEnter;
	QBooleanAction *keyActionFull;
	QBooleanAction *keyActionHome;
	QBooleanAction *keyActionLast;
	QBooleanAction *keyActionLevel;
	QBooleanAction *keyActionMark;
	QBooleanAction *keyActionMinus;
	QBooleanAction *keyActionNext;
	QBooleanAction *keyActionOut;
	QBooleanAction *keyActionPercentPlus;
	QBooleanAction *keyActionPercentMinus;
	QBooleanAction *keyActionPlus;
	QBooleanAction *keyActionQOnly;
	QBooleanAction *keyActionRemDim;
	QBooleanAction *keyActionSelectActive;
	QBooleanAction *keyActionSelectLast;
	QBooleanAction *keyActionSelectManual;
	QBooleanAction *keyActionSneak;
	QBooleanAction *keyActionSlash;
	QBooleanAction *keyActionTrace;

public slots:
	void setKeyPressed(QString keyName, bool pressed);

private:
	QOscUdpInterface iface;
	void setupKeyAction(QBooleanAction *action, QString keyName);
};
