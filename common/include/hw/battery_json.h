#pragma once

#include "../json_helper.h"
#include "battery.h"

typedef struct JSONBatteryHardware: public PWRBatteryHardware, JSONSerializer
{
    JSON_STRUCT("BatteryHardware")
    virtual void toJSON(QJsonObject &json);
    virtual bool fromJSON(const QJsonObject &json);
}JSONBatteryHardware;

