#include "battery.h"

Battery::Battery(QObject *parent) : BaseDevice(parent)
{
    ACState = true;
}

bool Battery::init()
{
    for(int i=0; i<batts.size(); i++)
    {
        delete batts[i];
    }
    batts.clear();
    unsigned int cnt;

    cnt = ACPIBattery::Count();
    for(unsigned int i=0; i<cnt; i++)
    {
        BatteryDevice* entry = new ACPIBattery(i);
        PWRBatteryStatus state;
        if (!entry->State(state))
        {
            continue;
        }
        batts.push_back(entry);
    }

    cnt = FakeBattery::Count();
    for(unsigned int i=0; i<cnt; i++)
    {
        BatteryDevice* entry = new FakeBattery(i);
        PWRBatteryStatus state;
        if (!entry->State(state))
        {
            continue;
        }
        batts.push_back(entry);
    }

    return batts.size();
}

int Battery::Count()
{
    return batts.size();
}

bool Battery::HardwareProbe()
{
    return true;
}

bool Battery::HardwareInfo(QJsonObject &obj)
{
    return false;
}

bool Battery::CurrentState(QJsonObject &obj)
{
    return false;
}

bool Battery::SetState(QJsonObject &obj)
{
    return false;
}

void Battery::ParseBatteries(bool isSilent)
{
    bool onAC = true;

    for(int i=0; i<batts.size(); i++)
    {
        if (batts[i]->Check())
        {
            if (!isSilent)
            {
                if (batts[i]->StateChanged())
                {
                    //emmit stat change for battery i
                }
                if (batts[i]->CapacityChanged())
                {
                    //emmit stat change for battery i
                }
            }
        }

        PWRBatteryStatus stat;
        if (!batts[i]->State(stat))
        {
            //error here
            continue;
        }

        onAC &= (stat.batteryState == BATT_CHARGING);

    }

    if ((!isSilent) && (onAC != ACState))
    {
        // emmit AC line state change event here
    }
    ACState = onAC;

    /*if (hasLowBattery) (*hasLowBattery) = false;
    for(int i=0; i<battHW.size(); i++)
    {
        //QVector<PWRBatteryStatus> currBatteryStates;
        JSONBatteryStatus curr;
        if (getBatteryStatus(i, curr))
        {
            curr.batteryCritical = (int)curr.batteryCapacity<=settings.lowBatteryCapacity;
            if ((curr.batteryState == BATT_DISCHARGING) && ((int)curr.batteryCapacity <= settings.lowBatteryCapacity))
            {
                if (hasLowBattery) (*hasLowBattery) = true;
            }
            if (curr.batteryCapacity != currBatteryStates[i].batteryCapacity)
            {
                QJsonObject event;
                event[BATTERY_NO] = i;
                event[JSONBatteryStatus().myname()] = curr.toJSON();
                emitEvent(EVENT_BATT_CAPACITY_CHANGED, event);
            }
            if (curr.batteryState != currBatteryStates[i].batteryState)
            {
                QJsonObject event;
                event[BATTERY_NO] = i;
                event[JSONBatteryStatus().myname()] = curr.toJSON();
                emitEvent(EVENT_BATT_STATE_CHANGED, event);
            }
            if (currBatteryStates.size() > i)
                currBatteryStates[i] = curr;
        }//if got battery status
    }//for all batteries*/
}
