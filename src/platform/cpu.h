#ifndef HYPERLIB_CPU_H
#define HYPERLIB_CPU_H

#define CPU_ARCH_X86_64 0
#define CPU_ARCH_I386 0
#define CPU_ARCH_AARCH64 0
#define CPU_ARCH_ARM 0
#define CPU_ARCH_PPC64 0
#define CPU_ARCH_AVR 0
#define CPU_ARCH_UNKNOWN 0

#if defined(__x86_64__) || defined(_M_X64)
    #undef CPU_ARCH_X86_64
    #define CPU_ARCH_X86_64 1
    #define CPU_ARCH "x86_64"
#elif defined(__i386__) || defined(_M_IX86)
    #undef CPU_ARCH_I386
    #define CPU_ARCH_I386 1
    #define CPU_ARCH "i386"
#elif defined(__aarch64__) || defined(_M_ARM64)
    #undef CPU_ARCH_AARCH64
    #define CPU_ARCH_AARCH64 1
    #define CPU_ARCH "AArch64"
#elif defined(__arm__) || defined(_M_ARM)
    #undef CPU_ARCH_ARM
    #define CPU_ARCH_ARM 1
    #define CPU_ARCH "ARM"
#elif defined(__ppc64__)
    #undef CPU_ARCH_PPC64
    #define CPU_ARCH_PPC64 1
    #define CPU_ARCH "PowerPC"
#elif defined(__avr__)
    #undef CPU_ARCH_AVR
    #define CPU_ARCH_AVR 1
    #define CPU_ARCH "AVR"
#else
    #undef CPU_ARCH_UNKNOWN
    #define CPU_ARCH_UNKNOWN 1
    #define CPU_ARCH "Unknown"
#endif

#if (HYPERLIB_PLATFORM_WIN64 || CPU_ARCH_X86_64 || CPU_ARCH_PPC64 || CPU_ARCH_AARCH64)
    #define HYPR_64BIT 1
    #define HYPR_32BIT 0
#elif (HYPERLIB_PLATFORM_WIN32 || CPU_ARCH_I386 || CPU_ARCH_ARM || CPU_ARCH_AVR)
    #define HYPR_64BIT 0
    #define HYPR_32BIT 1
#else
    #if defined(UINTPTR_MAX)
        #if UINTPTR_MAX == 0xffffffffffffffffULL
            #define HYPR_64BIT 1
            #define HYPR_32BIT 0
        #elif UINTPTR_MAX == 0xffffffff
            #define HYPR_64BIT 0
            #define HYPR_32BIT 1
        #else
            #warning "[WARN | hyprlib] Unsupported CPU bit size"
        #endif
    #else
        #warning "[WARN | hyprlib] Cannot determine CPU bit size"
    #endif
#endif

#endif