#ifndef HYPERLIB_OS_H
#define HYPERLIB_OS_H

#define HYPERLIB_PLATFORM_APPLE    0
#define HYPERLIB_PLATFORM_BSDI     0
#define HYPERLIB_PLATFORM_FREEBSD  0
#define HYPERLIB_PLATFORM_LINUX    0
#define HYPERLIB_PLATFORM_NETBSD   0
#define HYPERLIB_PLATFORM_OPENBSD  0
#define HYPERLIB_PLATFORM_UNIX     0
#define HYPERLIB_PLATFORM_WIN32    0
#define HYPERLIB_PLATFORM_WIN64    0

#if (defined(__APPLE__) && __APPLE__)
    #undef  HYPERLIB_PLATFORM_APPLE
    #define HYPERLIB_PLATFORM_APPLE 1
#endif

#if (defined(__bsdi__) && __bsdi__)
    #undef  HYPERLIB_PLATFORM_BSDI
    #define HYPERLIB_PLATFORM_BSDI 1
#endif

#if (defined(__FreeBSD__) && __FreeBSD__)
    #undef  HYPERLIB_PLATFORM_FREEBSD
    #define HYPERLIB_PLATFORM_FREEBSD 1
#endif

#if (defined(__linux__) || defined(__linux))
    #undef  HYPERLIB_PLATFORM_LINUX
    #define HYPERLIB_PLATFORM_LINUX 1
#endif

#if (defined(__NetBSD__) && __NetBSD__)
    #undef  HYPERLIB_PLATFORM_NETBSD
    #define HYPERLIB_PLATFORM_NETBSD 1
#endif

#if (defined(__OpenBSD__) && __OpenBSD__)
    #undef  HYPERLIB_PLATFORM_OPENBSD
    #define HYPERLIB_PLATFORM_OPENBSD 1
#endif

#if (defined(__unix__) || defined(__unix))
    #undef  HYPERLIB_PLATFORM_UNIX
    #define HYPERLIB_PLATFORM_UNIX 1
#endif

#if (defined(_WIN64))
    #undef  HYPERLIB_PLATFORM_WIN64
    #define HYPERLIB_PLATFORM_WIN64 1
#elif (defined(_WIN32))
    #undef  HYPERLIB_PLATFORM_WIN32
    #define HYPERLIB_PLATFORM_WIN32 1
#endif

#endif // HYPERLIB_OS_H
