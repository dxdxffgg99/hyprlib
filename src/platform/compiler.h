#ifndef HYPERLIB_COMPILER_H
#define HYPERLIB_COMPILER_H

#if (defined(__clang__))
    #define HYPERLIB_COMPILER_CLANG 1
    #define HYPERLIB_COMPILER_NAME "Clang"
#elif (defined(__GNUC__) || defined(__GNUG__))
    #define HYPERLIB_COMPILER_GCC 1
    #define HYPERLIB_COMPILER_NAME "GCC"
#elif (defined(_MSC_VER))
    #define HYPERLIB_COMPILER_MSVC 1
    #define HYPERLIB_COMPILER_NAME "MSVC"
#else
    #define HYPERLIB_COMPILER_UNKNOWN 1
    #define HYPERLIB_COMPILER_NAME "Unknown"
#endif

#if defined(__GNUC__) || defined(__clang__)
    #define HYPR_UNUSED __attribute__((unused))
#elif defined(_MSC_VER)
    #define HYPR_UNUSED
#else
    #define HYPR_UNUSED
#endif

#endif