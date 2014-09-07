#ifndef QDEVICEWATCHER_GLOBAL_H
#define QDEVICEWATCHER_GLOBAL_H

#if defined(Q_DLL_LIBRARY)
#  undef Q_DLL_EXPORT
#  define Q_DLL_EXPORT Q_DECL_EXPORT
#else
#  undef Q_DLL_EXPORT
#  define Q_DLL_EXPORT //Q_DECL_IMPORT //only for vc?
#endif

#endif // QDEVICEWATCHER_GLOBAL_H
