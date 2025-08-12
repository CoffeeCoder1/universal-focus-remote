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
}

void EosSettings::write(QJsonObject &json) const {
	json["model"] = modelString;
	json["name"] = name;
}

void EosSettings::setName(QString name) {
	this->name = name;
	emit nameChanged(name);
}

QString EosSettings::getName() const {
	return name;
}
