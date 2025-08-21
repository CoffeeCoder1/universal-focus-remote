#pragma once

#include "../../../actions/qbooleanaction.h"
#include "eossettings.h"
#include <QObject>
#include <QOsc>

class ETCEos : public QObject {
	Q_OBJECT

public:
	explicit ETCEos(EosSettings *settings, QObject *parent = nullptr);

	QOscTcpInterface *getInterface() { return &iface; };

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
	QBooleanAction *keyActionAbout;
	QBooleanAction *keyActionAssert;
	QBooleanAction *keyActionAt;
	QBooleanAction *keyActionBlock;
	QBooleanAction *keyActionCapture;
	QBooleanAction *keyActionClear;
	QBooleanAction *keyActionCopyTo;
	QBooleanAction *keyActionCue;
	QBooleanAction *keyActionDelete;
	QBooleanAction *keyActionEffect;
	QBooleanAction *keyActionEnter;
	QBooleanAction *keyActionFan;
	QBooleanAction *keyActionFull;
	QBooleanAction *keyActionGoToCue;
	QBooleanAction *keyActionHigh;
	QBooleanAction *keyActionHome;
	QBooleanAction *keyActionLabelNote;
	QBooleanAction *keyActionLast;
	QBooleanAction *keyActionLevel;
	QBooleanAction *keyActionMark;
	QBooleanAction *keyActionMinus;
	QBooleanAction *keyActionNext;
	QBooleanAction *keyActionOffset;
	QBooleanAction *keyActionOut;
	QBooleanAction *keyActionPark;
	QBooleanAction *keyActionPart;
	QBooleanAction *keyActionPath;
	QBooleanAction *keyActionPercentPlus;
	QBooleanAction *keyActionPercentMinus;
	QBooleanAction *keyActionPlus;
	QBooleanAction *keyActionQOnly;
	QBooleanAction *keyActionQuery;
	QBooleanAction *keyActionRecallFrom;
	QBooleanAction *keyActionRecord;
	QBooleanAction *keyActionRemDim;
	QBooleanAction *keyActionSelectActive;
	QBooleanAction *keyActionSelectLast;
	QBooleanAction *keyActionSelectManual;
	QBooleanAction *keyActionSneak;
	QBooleanAction *keyActionSlash;
	QBooleanAction *keyActionTrace;

public slots:
	void setKeyPressed(QString keyName, bool pressed);
	void queryPatchData(qint32 index);

signals:
	void userCommandLineChanged(QString text);

private:
	QOscTcpInterface iface;
	void setupKeyAction(QBooleanAction *action, QString keyName);
	void setupConnection();

	EosSettings *boardSettings;
};
