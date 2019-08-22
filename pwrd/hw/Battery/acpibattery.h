#ifndef ACPIBATTERY_H
#define ACPIBATTERY_H

#include "batteryhw.h"

class ACPIBattery:public BatteryHardware
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
