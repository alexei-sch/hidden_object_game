#if defined(BUILD_DB_LIB)
#define DB_EXPORT Q_DECL_EXPORT
#else
#define DB_EXPORT Q_DECL_IMPORT
#endif
