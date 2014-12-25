#pragma once

#define DECLARE_METATYPE(name) \
Q_DECLARE_METATYPE(name); \
static const int _var_##name = qRegisterMetaType<name>(#name);
