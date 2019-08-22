#pragma once

#include <QString>

//! Battery states
typedef enum
{
    BATT_CHARGING = 0, ///< Battery is charging
    BATT_DISCHARGING,  ///< Battery is discharging
    BATT_STATE_UNKNOWN,///< Battery state is unknown
    BATT_STATE_MAX
}PWRBatteryState;

//! Current battery state
typedef struct _PWRBatteryState
{
    PWRBatteryState batteryState;   ///< Current battery state
    unsigned int batteryCapacity;   ///< Battery capacity in percents (0..100)
    unsigned int powerConsumption;  ///< Current power consumption (in mW)
    unsigned int batteryTime;       ///< Battery lifetime (in minutes)
    bool         batteryCritical;
    _PWRBatteryState()
    {
        batteryState = BATT_STATE_UNKNOWN;
        batteryCapacity = 0;
        batteryTime = 0;
        powerConsumption = 0;
        batteryCritical = false;
    }
}PWRBatteryStatus;

//! Battery hardware info
typedef struct _PWRBatteryHardware
{
    QString      OEMInfo;          ///< OEM name
    QString      model;            ///< Battery model
    QString      serial;           ///< Battery serial number
    QString      type;             ///< Type of battary (LIon in most cases)
    unsigned int designCapacity;   ///< Design capacity (in mWh)
    unsigned int lastFullCapacity; ///< Last full charrrged capacity (in mWh)
    unsigned int designVoltage;    ///< Design voltage (in mV)
    _PWRBatteryHardware()
    {
        designCapacity = 0;
        lastFullCapacity = 0;
        designVoltage = 0;
    }
}PWRBatteryHardware;
