#ifndef HYPERLIB_CSTDVER_H
#define HYPERLIB_CSTDVER_H

#define HYPR_C89 0
#define HYPR_C95 0
#define HYPR_C99 0
#define HYPR_C11 0
#define HYPR_C17 0
#define HYPR_C23 0

#if !defined(__STDC_VERSION__)
    #undef  HYPR_C89
    #define HYPR_C89 1
    #define HYPR_CSTD_NAME "C89"

#elif (__STDC_VERSION__ >= 202311L)
    #undef  HYPR_C23
    #define HYPR_C23 1
    #define HYPR_CSTD_NAME "C23"

#elif (__STDC_VERSION__ >= 201710L)
    #undef  HYPR_C17
    #define HYPR_C17 1
    #define HYPR_CSTD_NAME "C17"

#elif (__STDC_VERSION__ >= 201112L)
    #undef  HYPR_C11
    #define HYPR_C11 1
    #define HYPR_CSTD_NAME "C11"

#elif (__STDC_VERSION__ >= 199901L)
    #undef  HYPR_C99
    #define HYPR_C99 1
    #define HYPR_CSTD_NAME "C99"

#elif (__STDC_VERSION__ >= 199409L)
    #undef  HYPR_C95
    #define HYPR_C95 1
    #define HYPR_CSTD_NAME "C95"

#else
    /* 정의는 되어 있으나 94년 이전인 경우 C89로 간주 */
    #undef  HYPR_C89
    #define HYPR_C89 1
    #define HYPR_CSTD_NAME "C89"
#endif

#endif