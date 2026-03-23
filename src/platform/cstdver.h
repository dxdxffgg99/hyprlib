#ifndef HYPERLIB_CSTDVER_H
#define HYPERLIB_CSTDVER_H

#define HYPR_C89 0
#define HYPR_C99 0
#define HYPR_C11 0
#define HYPR_C17 0
#define HYPR_C23 0

#if (!defined(__STDC_VERSION__))
    #undef  HYPR_C89
    #define HYPR_C89 1
    #define HYPR_CSTD_NAME "C89"
#elif __STDC_VERSION__ >= 202311L
    #define HYPR_C23 1
    #define HYPR_CSTD_NAME "C23"
#elif __STDC_VERSION__ >= 201710L
    #define HYPR_C17 1
    #define HYPR_CSTD_NAME "C17"
#elif __STDC_VERSION__ >= 201112L
    #define HYPR_C11 1
    #define HYPR_CSTD_NAME "C11"
#elif __STDC_VERSION__ >= 199901L
    #define HYPR_C99 1
    #define HYPR_CSTD_NAME "C99"
#elif __STDC_VERSION__ >= 199409L
    #define HYPR_C95 1
    #define HYPR_CSTD_NAME "C95"
#else
    #define HYPR_C89 1
    #define HYPR_CSTD_NAME "C89"
#endif

#endif