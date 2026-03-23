#ifndef HYPERLIB_OS_H
#define HYPERLIB_OS_H

#if	(defined(__APPLE__) && __APPLE__)
    #define	HYPERLIB_PLATFORM_APPLE	1
#else
    #define	HYPERLIB_PLATFORM_APPLE	0
#endif

#if	(defined(__bsdi__) && __bsdi__)
    #define	HYPERLIB_PLATFORM_BSDI	1
#else
    #define	HYPERLIB_PLATFORM_BSDI	0
#endif

#if	(defined(__FreeBSD__) && __FreeBSD__)
    #define	HYPERLIB_PLATFORM_FREEBSD	1
#else
    #define	HYPERLIB_PLATFORM_FREEBSD	0
#endif

#if	(defined(__linux) && __linux)
    #define	HYPERLIB_PLATFORM_LINUX	1
#else
    #define	HYPERLIB_PLATFORM_LINUX	0
#endif

#if	(defined(__NetBSD__) && __NetBSD__)
    #define	HYPERLIB_PLATFORM_NETBSD	1
#else
    #define	HYPERLIB_PLATFORM_NETBSD	0
#endif

#if	(defined(__OpenBSD__) && __OpenBSD__)
    #define	HYPERLIB_PLATFORM_OPENBSD	1
#else
    #define	HYPERLIB_PLATFORM_OPENBSD	0
#endif

#if	(defined(__unix) && __unix)
    #define	HYPERLIB_PLATFORM_UNIX	1
#else
    #define	HYPERLIB_PLATFORM_UNIX	0
#endif

#if (defined(_WIN64))
    #define HYPERLIB_PLATFORM_WIN64 1
    #define HYPERLIB_PLATFORM_WIN32 0
#elif (defined(_WIN32))
    #define HYPERLIB_PLATFORM_WIN64 0
    #define HYPERLIB_PLATFORM_WIN32 1
#else
    #define HYPERLIB_PLATFORM_WIN64 0
    #define HYPERLIB_PLATFORM_WIN32 0
#endif

#endif