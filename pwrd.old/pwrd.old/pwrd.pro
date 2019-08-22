QT += core network
QT -= gui

TARGET = pwrd
CONFIG += console c++11
#CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    hw/Battery/acpibattery.cpp \
    hw/Battery/battery.cpp \
    hw/Battery/batteryhw.cpp \
    hw/Battery/fakebattery.cpp \
    hw/backlight/backlight.cpp \
    hw/backlight/backlighthw.cpp \
    hw/device.cpp \
    pwrserver.cpp \
    sysctlutils.cpp \
    hw/battery.cpp \
    settingsreader.cpp \
    hw/backlight.cpp \
    profilereader.cpp \
    ../common/src/serialize.cpp \
    ../common/src/protocol.cpp \
    hw/intel_backlight.cpp \
    hw/buttons.cpp \
    comm_handlers.cpp \
    hw/sleep.cpp \
    hw/fakebatt.cpp

HEADERS += \
    hw/Battery/acpibattery.h \
    hw/Battery/battery.h \
    hw/Battery/batteryhw.h \
    hw/Battery/fakebattery.h \
    hw/backlight/backlight.h \
    hw/backlight/backlighthw.h \
    hw/device.h \
    pwrserver.h \
    sysctlutils.h \
    hw/battery.h \
    settingsreader.h \
    hw/backlight.h \
    profilereader.h \
    ../common/include/pwrdtypes.h \
    ../common/include/protocol.h \
    ../common/include/serialize.h \
    hw/intel_backlight.h \
    hw/buttons.h \
    hw/sleep.h \
    pwrddebug.h

INCLUDEPATH += ../common/include /usr/local/include/pwrd

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
