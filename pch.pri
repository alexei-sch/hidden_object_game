#precompiled options

PRECOMPILED_HEADER = pch.h
CONFIG += precompile_header

HEADERS -= $$files($$OUT_PWD/pch.h)
SOURCES -= $$files($$OUT_PWD/pch.h.cpp)
