#include "batterydev.h"

BatteryDevice::BatteryDevice(unsigned int idx)
{
    MyIndex = idx;
    Check();
}

bool BatteryDevice::Check()
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

bool BatteryDevice::CapacityChanged()
{
    return CapacityWasChanged;
}

bool BatteryDevice::StateChanged()
{
    return ChargingWasChanged;
}
