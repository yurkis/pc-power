#ifndef CBATTERYMANAGER_H
#define CBATTERYMANAGER_H

#include "../device.h"
#include "./dev/fakebattery.h"
#include "./dev/acpibattery.h"

#include <QObject>
#include <QVector>

class Battery : public BaseDevice
{
    Q_OBJECT
public:
    explicit Battery(QObject *parent = nullptr);

    bool init();
    int Count();

    void CheckBatteries();


signals:
    void BatteryLow(unsigned int idx);
    void ACLineStateChanged(bool isACPower);
public slots:


protected:
    virtual QString JSONName(){ return "battery"; }
    virtual QString Name()    { return "Battery"; }

    virtual bool HardwareProbe();
    virtual bool HardwareInfo(QJsonObject& obj);
    virtual bool CurrentState(QJsonObject& obj);
    virtual bool SetState(QJsonObject& obj);


private:
    QVector<BatteryDevice*> batts;
    bool lowBattery;
    bool ACState;

    void ParseBatteries(bool isSilent);

};

#endif // CBATTERYMANAGER_H
