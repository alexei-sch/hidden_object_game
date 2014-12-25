TEMPLATE = lib
CONFIG += shared

QT += testlib
QT += sql

include(../common.pri)

DEFINES += BUILD_DB_LIB

HEADERS += $$files($$PWD/*.h)
HEADERS += $$files($$PWD/tests/*.h)
SOURCES += $$files($$PWD/*.cpp)
SOURCES += $$files($$PWD/tests/*.cpp)

include(../pch.pri)

QMAKE_POST_LINK = xcopy \"data/ho.sqlite\" \"$$DESTDIR/*.*\" /D /Y /S /F