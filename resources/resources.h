#pragma once

#if defined(BUILD_RESOURCES_LIB)
#define RES_EXPORT Q_DECL_EXPORT
#else
#define RES_EXPORT Q_DECL_IMPORT
#endif
