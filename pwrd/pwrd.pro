QT += core network
QT -= gui

TARGET = pwrd
CONFIG += console c++11
#CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ../common/src/hw/battery_json.cpp \
    ../common/src/json_helper.cpp \
    hw/battery/dev/acpibattery.cpp \
    hw/battery/battery.cpp \
    hw/battery/batterydev.cpp \
    hw/battery/dev/fakebattery.cpp \
    hw/backlight/backlight.cpp \
    hw/backlight/backlighthw.cpp \
    hw/device.cpp \
    pwrdobject.cpp \
    pwrserver.cpp \
    settingsfile.cpp \
    sysctlutils.cpp \
    profilereader.cpp \
    ../common/src/serialize.cpp \
    ../common/src/protocol.cpp \
    hw/intel_backlight.cpp \
    hw/buttons.cpp \
    hw/sleep.cpp \

HEADERS += \
    ../common/include/hw/battery.h \
    ../common/include/hw/battery_json.h \
    ../common/include/json_helper.h \
    hw/battery/dev/acpibattery.h \
    hw/battery/battery.h \
    hw/battery/batterydev.h \
    hw/battery/dev/fakebattery.h \
    hw/backlight/backlight.h \
    hw/backlight/backlighthw.h \
    hw/device.h \
    pwrdobject.h \
    pwrserver.h \
    settingsfile.h \
    sysctlutils.h \
    hw/battery.h \
    profilereader.h \
    ../common/include/pwrdtypes.h \
    ../common/include/protocol.h \
    ../common/include/serialize.h \
    hw/intel_backlight.h \
    hw/buttons.h \
    hw/sleep.h \
    pwrddebug.h

INCLUDEPATH += ../common/include /usr/local/include/pwrd ../

QMAKE_LIBDIR = /usr/local/lib/qt5 /usr/local/lib
LIBS += -L/usr/local/lib

target.path=/usr/local/sbin

cleanprofiles.path=/usr/local/share/pcbsd/pwrd/
cleanprofiles.extra=rm -rf $(INSTALL_ROOT)/usr/local/share/pwrd/default

mkdirconf.path=/usr/local/share/pcbsd/pwrd/
mkdirconf.extra=mkdir -p $(INSTALL_ROOT)/usr/local/share/pwrd/

cpconfig.path=/usr/local/share/pwrd/
cpconfig.extra=tar cvf - -C conf . 2>/dev/null | tar xvf - -C $(INSTALL_ROOT)/usr/local/share/pwrd/ 2>/dev/null
#&& chmod -R 0555 $(INSTALL_ROOT)/usr/local/share/pcbsd/pc-power/ 2>/dev/null

rcd.path=/usr/local/etc/rc.d
rcd.extra=cp rc.d/pwrd $(INSTALL_ROOT)/usr/local/etc/rc.d/ && chmod -R 0555 $(INSTALL_ROOT)/usr/local/etc/rc.d/ pwrd

INSTALLS += target cleanprofiles mkdirconf cpconfig rcd

doc.commands = cd ../doc/pwrd/ && doxygen && cd ../../pwrd
QMAKE_EXTRA_TARGETS += doc