#ifndef CBATTERYMANAGER_H
#define CBATTERYMANAGER_H

#include "../device.h"
#include "fakebattery.h"
#include "acpibattery.h"

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

public:

private:
    QVector<BatteryHardware*> batts;
    bool lowBattery;
    bool ACState;

    void ParseBatteries(bool isSilent);
};

#endif // CBATTERYMANAGER_H
