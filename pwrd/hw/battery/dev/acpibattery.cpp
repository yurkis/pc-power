#include "acpibattery.h"

#ifndef FAKE_HARDWARE
#include <dev/acpica/acpiio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include <QDebug>


///////////////////////////////////////////////////////////////////////////////
static const char* const ACPIDEV = "/dev/acpi";
#define UNKNOWN_CAP 0xffffffff
#define UNKNOWN_VOLTAGE 0xffffffff

const int MAX_BATTS = 32;
#endif

ACPIBattery::ACPIBattery(unsigned int idx):BatteryDevice (idx)
{

}
#ifndef FAKE_HARDWARE

int ACPIBattery::Count()
{
    // UGLY CODE HERE
    // .. but it works
    static int      acpifd;
    int counter = 0;

    // Open ACPI device
    acpifd = open(ACPIDEV, O_RDWR);
    if (acpifd == -1)
        acpifd = open(ACPIDEV, O_RDONLY);
    if (acpifd == -1)
        return 0;

    for (int i=0; i<MAX_BATTS; i++)
    {
        union acpi_battery_ioctl_arg battio;
        battio.unit = i;
        if (ioctl(acpifd, ACPIIO_BATT_GET_BATTINFO, &battio) == -1) break;
        counter++;
    }
    close(acpifd);
    return counter;
}

bool ACPIBattery::HWInfo(PWRBatteryHardware &hw)
{
    static int      acpifd;

    // Open ACPI device
    acpifd = open(ACPIDEV, O_RDWR);
    if (acpifd == -1)
        acpifd = open(ACPIDEV, O_RDONLY);
    if (acpifd == -1)
        return false;


    //Make IOCTL call
    union acpi_battery_ioctl_arg battio;
    battio.unit = Index();
    if (ioctl(acpifd, ACPIIO_BATT_GET_BIF, &battio) == -1)
        return false;

    // Get battery H/W info
    hw.OEMInfo = QString(battio.bif.oeminfo);
    hw.model = QString (battio.bif.model);
    hw.serial = QString (battio.bif.serial);
    hw.type = QString(battio.bif.type);
    hw.designCapacity = (battio.bif.dcap != UNKNOWN_CAP)?battio.bif.dcap:0;
    hw.lastFullCapacity = (battio.bif.lfcap != UNKNOWN_CAP)?battio.bif.lfcap:0;
    hw.designVoltage = (battio.bif.dvol != UNKNOWN_CAP)? battio.bif.dvol:0;

    // If units are in mAh - recalculate in mWh
    if (battio.bif.units == ACPI_BIF_UNITS_MA)
    {
        //TODO: CHECK!
        hw.designCapacity= hwout.designCapacity * hwout.designVoltage / 100;
        hw.lastFullCapacity = hwout.lastFullCapacity * hwout.designVoltage / 100;
    }

    close(acpifd);

    return true;
}

bool ACPIBattery::State(PWRBatteryStatus &stat)
{
    static int      acpifd;

    // Open ACPI device
    acpifd = open(ACPIDEV, O_RDWR);
    if (acpifd == -1)
        acpifd = open(ACPIDEV, O_RDONLY);
    if (acpifd == -1)
        return false;

    union acpi_battery_ioctl_arg battio;
    battio.unit = Index();
    if (ioctl(acpifd, ACPIIO_BATT_GET_BATTINFO, &battio) == -1)
        return false;

    stat.batteryCapacity = battio.battinfo.cap;

    stat.batteryState = BATT_STATE_UNKNOWN;
    switch (battio.battinfo.state & ACPI_BATT_STAT_BST_MASK)
    {
        case ACPI_BATT_STAT_CHARGING:
            stat.batteryState = BATT_CHARGING;
            break;
        case ACPI_BATT_STAT_DISCHARG:
            stat.batteryState = BATT_DISCHARGING;
            break;
        case ACPI_BATT_STAT_CRITICAL:
            stat.batteryState = BATT_DISCHARGING;//BATT_CRITICAL;
            break;
    };

    stat.batteryTime = (battio.battinfo.min != -1)?battio.battinfo.min:0;


    // Get current power consumption
    stat.powerConsumption = 0;

    if (battio.battinfo.rate >=0 )
    {
        if ((battio.bif.units == ACPI_BIF_UNITS_MA) && battio.bst.volt != UNKNOWN_VOLTAGE)
        {
            // If units are in mAh
            stat.powerConsumption = battio.bst.volt * battio.battinfo.rate / 100 ;
         }
         else
         {
             stat.powerConsumption = battio.battinfo.rate;
         }
    }

    // Close ACPI device
    close(acpifd);

    return true;
}

#else
unsigned int ACPIBattery::Count()
{
    return 0;
}

bool ACPIBattery::HWInfo(PWRBatteryHardware &hw)
{
    Q_UNUSED(hw);
    return false;
}

bool ACPIBattery::State(PWRBatteryStatus &stat)
{
    Q_UNUSED(stat);
    return false;
}
#endif
