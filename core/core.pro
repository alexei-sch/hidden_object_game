TEMPLATE = lib
CONFIG += shared

QT += testlib
QT += xml

include(../common.pri)

DEFINES += BUILD_CORE_LIB

HEADERS += $$files($$PWD/*.h)
HEADERS += $$files($$PWD/tests/*.h)
HEADERS += $$files($$PWD/common/*.h)
HEADERS += $$files($$PWD/location/*.h)
HEADERS += $$files($$PWD/location/template/*.h)
HEADERS += $$files($$PWD/location/modelgenerator/*.h)
HEADERS += $$files($$PWD/location/model/*.h)
HEADERS += $$files($$PWD/location/timer/*.h)
HEADERS += $$files($$PWD/energy/*.h)
HEADERS += $$files($$PWD/game/*.h)
SOURCES += $$files($$PWD/*.cpp)
SOURCES += $$files($$PWD/tests/*.cpp)
SOURCES += $$files($$PWD/common/*.cpp)
SOURCES += $$files($$PWD/location/*.cpp)
SOURCES += $$files($$PWD/location/template/*.cpp)
SOURCES += $$files($$PWD/location/modelgenerator/*.cpp)
SOURCES += $$files($$PWD/location/model/*.cpp)
SOURCES += $$files($$PWD/location/timer/*.cpp)
SOURCES += $$files($$PWD/energy/*.cpp)
SOURCES += $$files($$PWD/game/*.cpp)

include(../pch.pri)

LIBS += resources.lib