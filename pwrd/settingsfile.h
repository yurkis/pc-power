#ifndef SETTINGSFILE_H
#define SETTINGSFILE_H

#include <QObject>

#include "pwrdobject.h"

static const char* const DEF_CONFIG_FILE = "/usr/local/share/pwrd/pwrd.conf";

class SettingsFile : public PWRDObject
{
    Q_OBJECT
public:
    explicit SettingsFile(QObject *parent = nullptr);

public:
    virtual QString JSONName(){return "settings";}
    virtual QString Name(){return "Settings";}

    bool load();
    bool save();

signals:

public slots:
};

#endif // SETTINGSFILE_H
