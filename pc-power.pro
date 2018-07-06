TEMPLATE = subdirs
CONFIG += recursive

SUBDIRS+= pwrd pwrcli dpower

#Make sure to list the library as a requirement for the others (for parallellized builds)
#binary.depends = library

RESOURCES += \
    dpower/pc-power.qrc \
    dpower/pc-power.qrc \
    dpower/pc-power.qrc \
    dpower/pc-power.qrc \
    dpower/pc-power.qrc

