TEMPLATE = app

include(../common.pri)

QT += testlib

HEADERS += $$files($$PWD/*.h)
SOURCES += $$files($$PWD/*.cpp)

include(../pch.pri)