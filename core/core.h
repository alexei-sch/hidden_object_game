#pragma once

#if defined(BUILD_CORE_LIB)
#define CORE_EXPORT Q_DECL_EXPORT
#else
#define CORE_EXPORT Q_DECL_IMPORT
#endif
