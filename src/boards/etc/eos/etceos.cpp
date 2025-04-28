#include "etceos.h"

#define SETUP_KEY_ACTION(action, keyString, shortcutKey) \
	action = new QBooleanAction();                       \
	action->setShortcut(shortcutKey);                    \
	setupKeyAction(action, keyString);

ETCEos::ETCEos(QObject *parent) :
		QObject{ parent } {
	// Bind the network interface so you can send and get messages
        iface.setRemoteAddress(QString("127.0.0.1"));
	iface.setRemotePort(8000);
	iface.setLocalPort(8001);

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
	SETUP_KEY_ACTION(keyActionAt, "at", new QKeySequence(Qt::Key_A));
	SETUP_KEY_ACTION(keyActionClear, "clear_cmd", new QKeySequence(Qt::Key_Backspace));
	SETUP_KEY_ACTION(keyActionEnter, "enter", new QKeySequence(Qt::Key_Return));
	SETUP_KEY_ACTION(keyActionFull, "full", new QKeySequence(Qt::Key_F));
	SETUP_KEY_ACTION(keyActionHome, "home", new QKeySequence(Qt::Key_Home));
	SETUP_KEY_ACTION(keyActionLast, "last", new QKeySequence(Qt::Key_PageUp));
	SETUP_KEY_ACTION(keyActionLevel, "level", new QKeySequence(Qt::CTRL | Qt::Key_V));
	SETUP_KEY_ACTION(keyActionMark, "mark", nullptr);
	SETUP_KEY_ACTION(keyActionMinus, "-", new QKeySequence(Qt::Key_Minus));
	SETUP_KEY_ACTION(keyActionNext, "next", new QKeySequence(Qt::Key_PageDown));
	SETUP_KEY_ACTION(keyActionOut, "out", new QKeySequence(Qt::Key_O));
	// TODO: Fix these
	SETUP_KEY_ACTION(keyActionPercentMinus, "-%", new QKeySequence("Ctrl+t"));
	SETUP_KEY_ACTION(keyActionPercentPlus, "+%", new QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_Equal));
	SETUP_KEY_ACTION(keyActionPlus, "+", new QKeySequence(Qt::Key_Equal));
	SETUP_KEY_ACTION(keyActionQOnly, "cueonlytrack", new QKeySequence(Qt::Key_X));
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
