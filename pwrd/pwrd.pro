QT += core network
QT -= gui

TARGET = pwrd
CONFIG += console c++11

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        pwrserver.cpp

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

HEADERS += \
    pwrserver.h
