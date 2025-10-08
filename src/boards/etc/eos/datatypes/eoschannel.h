#pragma once

#include <QObject>

class EosChannel : public QObject {
	Q_OBJECT

public:
	explicit EosChannel(QObject *parent = nullptr);

	void setChannelNumber(qint32 newChannelNumber);
	void setPartNumber(qint32 newPartNumber);
	void setLabel(QString newLabel);
	void setFixtureManufacturer(QString newFixtureManufacturer);
	void setFixtureModel(QString newFixtureModel);
	void setAddress(qint32 newAddress);
	void setIntensityAddress(qint32 newIntensityAddress);
	void setLevel(qint32 newLevel);
	void setOscGel(QString newOscGel);
	void setText1(QString newText1);
	void setText2(QString newText2);
	void setText3(QString newText3);
	void setText4(QString newText4);
	void setText5(QString newText5);
	void setText6(QString newText6);
	void setText7(QString newText7);
	void setText8(QString newText8);
	void setText9(QString newText9);
	void setText10(QString newText10);
	void setPartCount(qint32 newPartCount);

	qint32 channelNumber;
	qint32 partNumber;
	QString uid;
	QString label;
	QString fixtureManufacturer;
	QString fixtureModel;
	qint32 address;
	qint32 intensityAddress;
	qint32 level;
	QString oscGel;
	QString text1;
	QString text2;
	QString text3;
	QString text4;
	QString text5;
	QString text6;
	QString text7;
	QString text8;
	QString text9;
	QString text10;
	qint32 partCount;

signals:
	void updated();
};
