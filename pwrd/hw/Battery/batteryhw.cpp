#include "batteryhw.h"

BatteryHardware::BatteryHardware(unsigned int idx)
{
    MyIndex = idx;
    Check();
}

bool BatteryHardware::Check()
{
    PWRBatteryStatus st;
    if (! State(st))
    {
        return false;
    }
    ChargingWasChanged = (st.batteryState != LastState.batteryState);
    CapacityWasChanged = (st.batteryCapacity != LastState.batteryCapacity);

    LastState = st;

    return ChargingWasChanged || CapacityWasChanged;
}

bool BatteryHardware::CapacityChanged()
{
    return CapacityWasChanged;
}

bool BatteryHardware::StateChanged()
{
    return ChargingWasChanged;
}
