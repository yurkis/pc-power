#ifndef BACKLIGHTHW_H
#define BACKLIGHTHW_H

#include <QVector>

typedef struct _PWRBacklightHardware
{
    QVector<unsigned int> backlightLevels;
    _PWRBacklightHardware()
    {

    }
}PWRBacklightHardware;

class BacklightDevice
{
public:
    BacklightDevice(unsigned int idx);

    virtual bool HWInfo(PWRBacklightHardware& hw) =0;
    virtual bool State(unsigned int level) = 0;
    virtual bool Set(unsigned int level) = 0;

    virtual ~BacklightDevice(){}

protected:
    unsigned int Index() {return MyIndex;}
    unsigned int MyIndex;
};

#endif // BACKLIGHTHW_H
