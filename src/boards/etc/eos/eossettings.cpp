#include "eossettings.h"

const QString EosSettings::modelString = "etc.eos";

EosSettings::EosSettings(QObject *parent) :
		QObject{ parent } {
}

void EosSettings::read(const QJsonObject &json) {
	if (json.contains("model") && json["model"].isString())
		if (json["model"] != modelString) {
			qWarning() << "Model name mismatch.\n\tClass model: "
					   << modelString
					   << "\n\tGiven model: "
					   << json["model"].toString()
					   << "\n";
			return;
		}

	if (json.contains("name") && json["name"].isString())
		name = json["name"].toString();

	if (json.contains("ip") && json["ip"].isString())
		ip = json["ip"].toString();
}

void EosSettings::write(QJsonObject &json) const {
	json["model"] = modelString;
	json["name"] = name;
	json["ip"] = ip;
}

void EosSettings::setName(QString name) {
	this->name = name;
	emit nameChanged(name);
	emit updated();
}

QString EosSettings::getName() const {
	return name;
}

void EosSettings::setIp(QString ip) {
	this->ip = ip;
	emit ipChanged(ip);
	emit updated();
}

QString EosSettings::getIp() const {
	return ip;
}
