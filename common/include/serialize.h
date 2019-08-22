
/*!
\file
\brief PWRD data types serializers for JSON protocol
*/

#ifndef SERIALIZE_H
#define SERIALIZE_H

#include "pwrdtypes.h"

#include "json_helper.h"

typedef struct JSONHWInfo: public PWRHWInfo, public JSONSerializer
{
    JSON_STRUCT("HWInfo")
    virtual void toJSON(QJsonObject &json);
    virtual bool fromJSON(const QJsonObject &json);
}JSONHWInfo;


typedef struct JSONBacklightHardware: public PWRBacklightHardware, JSONSerializer
{
    JSON_STRUCT("BacklightHardware");
    virtual void toJSON(QJsonObject &json);
    virtual bool fromJSON(const QJsonObject &json);
}JSONBacklightHardware;

typedef struct JSONProfile:public PWRProfile, public JSONSerializer
{
    JSON_STRUCT("Profile");
    JSONProfile(){;};
    JSONProfile(const PWRProfile& in);
    virtual void toJSON(QJsonObject &json);
    virtual bool fromJSON(const QJsonObject &json);
}JSONProfile;

typedef struct _JSONBatteryStatus: public PWRBatteryStatus, public JSONSerializer
{
    JSON_STRUCT("BatteryStatus")
    virtual void toJSON(QJsonObject &json);
    virtual bool fromJSON(const QJsonObject &json);
}JSONBatteryStatus;

typedef struct _JSONDaemonSettings: public PWRDaemonSettings, JSONSerializer
{
    JSON_STRUCT("DaemonSettings")
    virtual void toJSON(QJsonObject &json);
    virtual bool fromJSON(const QJsonObject &json);
}JSONDaemonSettings;

#endif // SERIALIZE_H

