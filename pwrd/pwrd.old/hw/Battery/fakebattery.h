#ifndef FAKEBATTERY_H
#define FAKEBATTERY_H

#include "batteryhw.h"

class FakeBattery: public BatteryHardware
{
public:
    FakeBattery(unsigned int idx);

    static unsigned int Count();
    virtual bool HWInfo(PWRBatteryHardware& hw);
    virtual bool State(PWRBatteryStatus& stat);

private:
    PWRBatteryHardware hwout;
};

#endif // FAKEBATTERY_H
