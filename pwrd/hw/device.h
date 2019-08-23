#ifndef CDEVICE_H
#define CDEVICE_H

#include <QJsonObject>

#include <QObject>
#include "../pwrdobject.h"

class BaseDevice : public PWRDObject
{
    Q_OBJECT
public:
    explicit BaseDevice(QObject *parent = nullptr);

signals:

public slots:

public:    
    virtual bool HardwareProbe()=0;
    virtual bool Init(QJsonObject* settings) {Q_UNUSED(settings); return true;}
    virtual bool ReadProfile(QJsonObject& obj){Q_UNUSED(obj); return false;}
    virtual bool HardwareInfo(QJsonObject& obj){Q_UNUSED(obj); return false;}
    virtual bool CurrentState(QJsonObject& obj){Q_UNUSED(obj); return false;}
    virtual bool SetState(QJsonObject& obj){Q_UNUSED(obj); return false;}

};

#endif // CDEVICE_H
