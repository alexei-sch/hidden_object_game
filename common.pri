QT += opengl

CONFIG(release, debug|release) {
	CONFIG_NAME = release
}

CONFIG(debug, debug|release) {
	CONFIG_NAME = debug
}

DESTDIR = $(SolutionDir)/bin/$$CONFIG_NAME
QMAKE_LIBDIR += $$DESTDIR

CONFIG += qt warn_on
CONFIG -=flat

DEFINES += QT_NO_KEYWORDS

# treat warnings as errors
QMAKE_CXXFLAGS += /WX 

INCLUDEPATH += ../
INCLUDEPATH += ./

MOC_DIR  += generatedfiles/moc
UI_DIR   += generatedfiles/ui
RCC_DIR  += generatedfiles/rcc
OBJECTS_DIR = obj/$$CONFIG_NAME
