#ifndef JSON_HELPER_H
#define JSON_HELPER_H

#include <QJsonObject>
#include <QJsonArray>

static const char* const CHARGING = "charging";
static const char* const DISCHARGING = "discharging";
static const char* const UNKNOWN = "unknown";

typedef struct JSONSerializer
{
public:
    virtual void toJSON(QJsonObject &json)=0;
    virtual bool fromJSON(const QJsonObject &json)=0;
    virtual QString myname()=0;

    QString toJSONString();
    virtual QJsonObject toJSON();

    virtual ~JSONSerializer(){}

}JSONSerializer;

#define JSON_STRUCT(name)\
    virtual QString myname(){return name;}\
    using JSONSerializer::toJSON;   //that behavour surpise me :(

template <typename T>
void QVector2JSON(QString array_name, QVector<T> vec, QJsonObject &obj)
{
    QJsonArray arr;
    for(int i=0; i< vec.size(); i++)
    {
        QJsonObject obj;
        vec[i].toJSON(obj);
        arr.append(obj);
    }
    obj[array_name] = arr;
}

template <typename T>
QJsonObject QVector2JSON(QString array_name, QVector<T> vec)
{
    QJsonObject obj;
    QJsonArray arr;
    for(int i=0; i< vec.size(); i++)
    {
        QJsonObject obj;
        vec[i].toJSON(obj);
        arr.append(obj);
    }
    obj[array_name] = arr;
    return obj;
}

QString QJsonObject2String(QJsonObject obj);

#define PWRD_JSON_FIELD(json_field, structure_field)\
    if (json.find(json_field) != json.end()) structure_field = json[json_field]

#define PWRD_JSON_FIELD_REQUIRED(json_field, structure_field)\
    if (!json.contains(json_field)) return false;\
        else structure_field = json[json_field];

#endif // JSON_HELPER_H
