#include "hw/battery_json.h"

void JSONBatteryHardware::toJSON(QJsonObject &json)
{
    json["OEMInfo"] = OEMInfo;
    json["model"] = model;
    json["serial"] = serial;
    json["type"] = type;
    json["designCapacity"] = static_cast<int>(designCapacity);
    json["lastFullCapacity"] = (static_cast<int>(lastFullCapacity));
    json["designVoltage"] = (static_cast<int>(designVoltage));
}

bool JSONBatteryHardware::fromJSON(const QJsonObject &json)
{
    PWRD_JSON_FIELD("OEMInfo", OEMInfo).toString();
    PWRD_JSON_FIELD("model", model).toString();
    PWRD_JSON_FIELD("serial", serial).toString();
    PWRD_JSON_FIELD("type", type).toString();
    PWRD_JSON_FIELD("designCapacity", designCapacity).toInt();
    PWRD_JSON_FIELD("lastFullCapacity", lastFullCapacity).toInt();
    PWRD_JSON_FIELD("designVoltage", designVoltage).toInt();
    return true;
}
