#include "etceos.h"

#define SETUP_KEY_ACTION(action, keyString, shortcutKey) \
	action = new QBooleanAction();                       \
	action->setShortcut(shortcutKey);                    \
	setupKeyAction(action, keyString);

ETCEos::ETCEos(EosSettings *settings, QObject *parent) :
		QObject{ parent } {
	boardSettings = settings;

	connect(&iface, &QOscTcpInterface::connected, this, &ETCEos::setupConnection);

	iface.connect("/eos/out/cmd", [=](const QOscMessage &msg) { emit userCommandLineChanged(msg.toString()); });

	// Bind the network interface so you can send and get messages
	qDebug() << "Connecting to board with IP"
			 << boardSettings->getIp();
	iface.setRemoteAddress(boardSettings->getIp());
	iface.setRemotePort(3037);

	// Setup keypad actions
	SETUP_KEY_ACTION(keyAction0, "0", new QKeySequence(Qt::Key_0));
	SETUP_KEY_ACTION(keyAction1, "1", new QKeySequence(Qt::Key_1));
	SETUP_KEY_ACTION(keyAction2, "2", new QKeySequence(Qt::Key_2));
	SETUP_KEY_ACTION(keyAction3, "3", new QKeySequence(Qt::Key_3));
	SETUP_KEY_ACTION(keyAction4, "4", new QKeySequence(Qt::Key_4));
	SETUP_KEY_ACTION(keyAction5, "5", new QKeySequence(Qt::Key_5));
	SETUP_KEY_ACTION(keyAction6, "6", new QKeySequence(Qt::Key_6));
	SETUP_KEY_ACTION(keyAction7, "7", new QKeySequence(Qt::Key_7));
	SETUP_KEY_ACTION(keyAction8, "8", new QKeySequence(Qt::Key_8));
	SETUP_KEY_ACTION(keyAction9, "9", new QKeySequence(Qt::Key_9));
	SETUP_KEY_ACTION(keyActionAbout, "about", new QKeySequence(Qt::Key_Y));
	SETUP_KEY_ACTION(keyActionAssert, "assert", new QKeySequence("Ctrl+W"));
	SETUP_KEY_ACTION(keyActionAt, "at", new QKeySequence(Qt::Key_A));
	SETUP_KEY_ACTION(keyActionBlock, "block", new QKeySequence(Qt::Key_B));
	SETUP_KEY_ACTION(keyActionCapture, "capture", new QKeySequence("Ctrl+Alt+P"));
	SETUP_KEY_ACTION(keyActionClear, "clear_cmd", new QKeySequence(Qt::Key_Backspace));
	SETUP_KEY_ACTION(keyActionCopyTo, "copy_to", new QKeySequence(Qt::Key_C));
	SETUP_KEY_ACTION(keyActionCue, "cue", new QKeySequence(Qt::Key_Q));
	SETUP_KEY_ACTION(keyActionDelete, "delete", new QKeySequence(Qt::Key_Delete));
	SETUP_KEY_ACTION(keyActionEffect, "effect", new QKeySequence("Alt+E"));
	SETUP_KEY_ACTION(keyActionEnter, "enter", new QKeySequence(Qt::Key_Return));
	SETUP_KEY_ACTION(keyActionFan, "fan_", new QKeySequence(Qt::Key_W));
	SETUP_KEY_ACTION(keyActionFull, "full", new QKeySequence(Qt::Key_F));
	SETUP_KEY_ACTION(keyActionGoToCue, "go_to_cue", new QKeySequence("Ctrl+G"));
	SETUP_KEY_ACTION(keyActionHigh, "highlight", new QKeySequence(Qt::Key_Backslash));
	SETUP_KEY_ACTION(keyActionHome, "home", new QKeySequence(Qt::Key_Home));
	SETUP_KEY_ACTION(keyActionLabelNote, "label", new QKeySequence(Qt::Key_L));
	SETUP_KEY_ACTION(keyActionLast, "last", new QKeySequence(Qt::Key_PageUp));
	SETUP_KEY_ACTION(keyActionLevel, "level", new QKeySequence(Qt::CTRL | Qt::Key_V));
	SETUP_KEY_ACTION(keyActionMark, "mark", nullptr);
	SETUP_KEY_ACTION(keyActionMinus, "-", new QKeySequence(Qt::Key_Minus));
	SETUP_KEY_ACTION(keyActionNext, "next", new QKeySequence(Qt::Key_PageDown));
	SETUP_KEY_ACTION(keyActionOffset, "offset", new QKeySequence("Ctrl+O"));
	SETUP_KEY_ACTION(keyActionOut, "out", new QKeySequence(Qt::Key_O));
	SETUP_KEY_ACTION(keyActionPark, "park", new QKeySequence("Alt+K"));
	SETUP_KEY_ACTION(keyActionPart, "part", new QKeySequence(Qt::Key_P));
	// TODO: Fix these
	SETUP_KEY_ACTION(keyActionPath, "path", new QKeySequence("Ctrl+Alt+W"));
	SETUP_KEY_ACTION(keyActionPercentMinus, "-%", new QKeySequence("Ctrl+t"));
	SETUP_KEY_ACTION(keyActionPercentPlus, "+%", new QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_Equal));
	SETUP_KEY_ACTION(keyActionPlus, "+", new QKeySequence(Qt::Key_Equal));
	SETUP_KEY_ACTION(keyActionQOnly, "cueonlytrack", new QKeySequence(Qt::Key_X));
	SETUP_KEY_ACTION(keyActionQuery, "query", new QKeySequence("Ctrl+Q"));
	SETUP_KEY_ACTION(keyActionRecallFrom, "recall_from", new QKeySequence(Qt::Key_E));
	SETUP_KEY_ACTION(keyActionRecord, "record", new QKeySequence(Qt::Key_R));
	SETUP_KEY_ACTION(keyActionRemDim, "rem_dim", new QKeySequence(Qt::Key_H));
	SETUP_KEY_ACTION(keyActionSelectActive, "select_active", new QKeySequence(Qt::CTRL | Qt::Key_A));
	SETUP_KEY_ACTION(keyActionSelectLast, "select_last", new QKeySequence(Qt::CTRL | Qt::Key_L));
	SETUP_KEY_ACTION(keyActionSelectManual, "select_manual", new QKeySequence(Qt::CTRL | Qt::Key_M));
	SETUP_KEY_ACTION(keyActionSneak, "sneak", new QKeySequence(Qt::Key_N));
	SETUP_KEY_ACTION(keyActionSlash, "\\", new QKeySequence(Qt::Key_Slash));
	SETUP_KEY_ACTION(keyActionTrace, "trace", new QKeySequence(Qt::Key_J));
}

void ETCEos::setKeyPressed(QString keyName, bool pressed) {
	// Craft the message you want to send
	QOscMessage msg(QString("/eos/key/" + keyName), pressed);

	iface.send(msg);
}

void ETCEos::setupKeyAction(QBooleanAction *action, QString keyName) {
	connect(action, &QBooleanAction::valueChanged, this, [=](bool value) { setKeyPressed(keyName, value); });
}

void ETCEos::setupConnection() {
	qDebug() << "Connected to board";

	QOscBundle bundle;
	bundle << QOscMessage("/eos/user", 1);
	iface.send(bundle);
}

void ETCEos::queryPatchData(qint32 index) {
	QOscMessage msg("/eos/get/patch/index", index);
	iface.send(msg);
}
