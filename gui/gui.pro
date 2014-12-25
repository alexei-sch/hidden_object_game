TEMPLATE = lib
CONFIG += shared

include(../common.pri)

DEFINES += BUILD_GUI_LIB

HEADERS += $$files($$PWD/*.h)
HEADERS += $$files($$PWD/location/*.h)
HEADERS += $$files($$PWD/game/*.h)
HEADERS += $$files($$PWD/energy/*.h)
HEADERS += $$files($$PWD/mainscreen/*.h)
HEADERS += $$files($$PWD/common/*.h)
HEADERS += $$files($$PWD/dialogs/*.h)
SOURCES += $$files($$PWD/*.cpp)
SOURCES += $$files($$PWD/location/*.cpp)
SOURCES += $$files($$PWD/game/*.cpp)
SOURCES += $$files($$PWD/energy/*.cpp)
SOURCES += $$files($$PWD/mainscreen/*.cpp)
SOURCES += $$files($$PWD/common/*.cpp)
SOURCES += $$files($$PWD/dialogs/*.cpp)

include(../pch.pri)

LIBS += core.lib resources.lib