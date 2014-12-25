#pragma once

#if defined(BUILD_GUI_LIB)
#define GUI_EXPORT Q_DECL_EXPORT
#else
#define GUI_EXPORT Q_DECL_IMPORT
#endif
