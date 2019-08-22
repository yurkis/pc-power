#include "fakebattery.h"

#include <QFile>
#include <QTextStream>

const unsigned int FAKE_COUNT = 2;
const char* const FAKE_FILE_PREFFIX = "~/battery";


FakeBattery::FakeBattery(unsigned int idx):BatteryHardware (idx)
{
    hwout.type="LIon";
    hwout.OEMInfo=QString("FakeBatt") + QString::number(idx);
    hwout.model=QString("Fake") /*+ QString::number(batt)*/;
    hwout.designVoltage = 7400;
    hwout.serial=QString("0000-0000-000") + QString::number(idx);
    hwout.designCapacity=38006;
    hwout.lastFullCapacity=29289;
}

unsigned int FakeBattery::Count()
{
#ifdef FAKE_HARDWARE
    return FAKE_COUNT;
#else
    return 0;
#endif
}

bool FakeBattery::HWInfo(PWRBatteryHardware &hw)
{
    hw = hwout;
    return true;
}

bool FakeBattery::State(PWRBatteryStatus &stat)
{
    QFile file(QString(FAKE_FILE_PREFFIX)+QString::number(Index()));
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        stat.batteryState = BATT_CHARGING;
        stat.batteryCapacity = 100 - Index()*10;
        stat.powerConsumption = 500;
        stat.batteryTime = 0;
        return true;
    }
    QTextStream s(&file);
    QString str;
    str = s.readLine();
    stat.batteryCapacity = static_cast<unsigned int>(str.toInt());
    str = s.readLine();
    if (str.toLower().trimmed() == QString("c"))
        stat.batteryState = BATT_CHARGING;
    else
        stat.batteryState = BATT_DISCHARGING;
    str = s.readLine();
    stat.batteryTime = static_cast<unsigned int>(str.toInt());
    str = s.readLine();
    stat.powerConsumption = static_cast<unsigned int>(str.toInt());

    return true;
}
