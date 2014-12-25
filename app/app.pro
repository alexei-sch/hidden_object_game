TEMPLATE = app

include(../common.pri)

HEADERS += $$files($$PWD/*.h)
SOURCES += $$files($$PWD/*.cpp)

include(../pch.pri)

LIBS += core.lib gui.lib db.lib
