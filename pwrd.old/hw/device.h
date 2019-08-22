#ifndef CDEVICE_H
#define CDEVICE_H

#include <QJsonObject>

#include <QObject>

class BaseDevice : public QObject
{
    Q_OBJECT
public:
    explicit BaseDevice(QObject *parent = nullptr);

signals:

public slots:

public:
    virtual QString JSONName()=0;
    virtual QString Name()=0;
    virtual bool HardwareProbe();
    virtual bool ReadProfile(QJsonObject& obj){Q_UNUSED(obj); return false;}
    virtual bool HardwareInfo(QJsonObject& obj){Q_UNUSED(obj); return false;}
    virtual bool CurrentState(QJsonObject& obj){Q_UNUSED(obj); return false;}
    virtual bool SetState(QJsonObject& obj){Q_UNUSED(obj); return false;}

};

#endif // CDEVICE_H