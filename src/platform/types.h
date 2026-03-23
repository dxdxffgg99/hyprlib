#ifndef HYPERLIB_TYPES_H
#define HYPERLIB_TYPES_H

#include <stdint.h>
#include <limits.h>

#if (CHAR_BIT != 8)
    #error "[ERROR | hyprlib] char must be 1-byte"
#endif

#if (SHRT_MAX != 32767)
    #error "[ERROR | hyprlib] short must be 2-byte"
#endif

#if (INT_MAX != 2147483647)
    #error "[ERROR | hyprlib] int must be 4-byte"
#endif

#if (LLONG_MAX != 9223372036854775807LL)
    #error "[ERROR | hyprlib] long long must be 8-byte"
#endif

#endif