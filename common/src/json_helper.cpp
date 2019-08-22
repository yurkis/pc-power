#include "json_helper.h"

QString QJsonObject2String(QJsonObject obj)
{
    QJsonDocument doc (obj);
    return doc.toJson();
}

QString JSONSerializer::toJSONString()
{
    QJsonObject obj;
    toJSON(obj);
    return QJsonObject2String(obj);
}

QJsonObject JSONSerializer::toJSON()
{
    QJsonObject obj;
    toJSON(obj);
    return obj;
}
