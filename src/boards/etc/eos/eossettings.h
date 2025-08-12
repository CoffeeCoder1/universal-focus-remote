#pragma once

#include <QJsonObject>

class EosSettings : public QObject {
	Q_OBJECT

	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged FINAL);

public:
	explicit EosSettings(QObject *parent = nullptr);

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;

	QString getName() const;
	void setName(QString name);

	static const QString modelString;

signals:
	void nameChanged(QString name);

private:
	QString name;
};
