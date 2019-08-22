#ifndef ACPIBATTERY_H
#define ACPIBATTERY_H

#include "../batterydev.h"

class ACPIBattery:public BatteryDevice
{
public:
    ACPIBattery(unsigned int idx);

    static unsigned int Count();
    virtual bool HWInfo(PWRBatteryHardware& hw);
    virtual bool State(PWRBatteryStatus& stat);

private:
    PWRBatteryHardware hwout;
};

#endif // ACPIBATTERY_H
