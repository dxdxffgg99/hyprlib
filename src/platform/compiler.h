#ifndef HYPERLIB_COMPILER_H
#define HYPERLIB_COMPILER_H

#define HYPERLIB_COMPILER_CLANG 0
#define HYPERLIB_COMPILER_GCC 0
#define HYPERLIB_COMPILER_MSVC 0

#if (defined(__clang__) && __clang__)
    #undef HYPERLIB_COMPILER_CLANG
    #define HYPERLIB_COMPILER_CLANG 1
    #define HYPERLIB_COMPILER_NAME "Clang"
#elif (defined(__GNUC__))
    #undef HYPERLIB_COMPILER_GCC
    #define HYPERLIB_COMPILER_GCC 1
    #define HYPERLIB_COMPILER_NAME "GCC"
#elif (defined(_MSC_VER))
    #undef HYPERLIB_COMPILER_MSVC
    #define HYPERLIB_COMPILER_MSVC 1
    #define HYPERLIB_COMPILER_NAME "MSVC"
#else
    #define HYPERLIB_COMPILER_UNKNOWN 1
    #define HYPERLIB_COMPILER_NAME "Unknown"
#endif

#endif