TEMPLATE = lib
CONFIG += shared

include(../common.pri)

HEADERS += *.h
SOURCES += *.cpp
RESOURCES = resources.qrc

DEFINES += BUILD_RESOURCES_LIB

include(../pch.pri)