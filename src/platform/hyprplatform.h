#ifndef HYPERLIB_PLATFORM_H
#define HYPERLIB_PLATFORM_H

#include "compiler.h"
#include "cpu.h"
#include "cstdver.h"
#include "os.h"
#include "types.h"

#if (defined(__STDC_VERSION__) && HYPR_C99)
    #define hypr_inline inline
#elif (HYPERLIB_COMPILER_MSVC)
    #define hypr_inline __inline
#else
    #define hypr_inline
#endif

#if ((defined(__STDC_VERSION__) && HYPR_C99) || defined(__GNUC__))
    #define hypr_restrict restrict
#elif (HYPERLIB_COMPILER_MSVC)
    #define hypr_restrict __restrict
#else
    #define hypr_restrict
#endif

#if (HYPERLIB_COMPILER_MSVC && !defined(_CRT_SECURE_NO_WARNINGS))
    #define _CRT_SECURE_NO_WARNINGS
#endif

#if (HYPERLIB_COMPILER_MSVC)
    #define hypr_unused(x) (void)(x)
#else
    #define hypr_unused(x) (void)(__typeof__(x))(x)
#endif

#endif