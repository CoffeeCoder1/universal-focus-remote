#include "eoschannel.h"

#include <QDebug>

EosChannel::EosChannel(QObject *parent) :
		QObject{ parent } {
	connect(this, &EosChannel::updated, [=]() {
		qDebug() << channelNumber
				 << partNumber
				 << uid
				 << label
				 << fixtureManufacturer
				 << fixtureModel
				 << address
				 << intensityAddress
				 << level
				 << oscGel
				 << text1
				 << text2
				 << text3
				 << text4
				 << text5
				 << text6
				 << text7
				 << text8
				 << text9
				 << text10
				 << partCount;
	});
}
