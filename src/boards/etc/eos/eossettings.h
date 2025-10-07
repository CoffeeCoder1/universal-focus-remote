#pragma once

#include <QJsonObject>

class EosSettings : public QObject {
	Q_OBJECT

	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged FINAL);
	Q_PROPERTY(QString ip READ getIp WRITE setIp NOTIFY ipChanged FINAL);

public:
	explicit EosSettings(QObject *parent = nullptr);

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
	void remove();

	void setName(QString name);
	QString getName() const;
	void setIp(QString ip);
	QString getIp() const;

	static const QString modelString;

signals:
	void updated();
	void removed();
	void nameChanged(QString name);
	void ipChanged(QString ip);

private:
	QString name;
	QString ip = "127.0.0.1";
};
