#ifndef HYPER_LIBRARY_CORE_H
#define HYPER_LIBRARY_CORE_H

#include "./src/algorithm/algo.h"
#include "./src/platform/platform.h"
#include "./src/math/math.h"

#define swap(x, y) do { \
    typeof(x) _t = (x); \
    (x) = (y);          \
    (y) = _t;           \
} while (0)

static inline char *itoa(int num, char *str, int base) {
    int i = 0;
    long long n = num;
    int isNegative = 0;

    if (n == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (n < 0 && base == 10) {
        isNegative = 1;
        n = -n;
    }

    while (n > 0) {
        int rem = n % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        n /= base;
    }

    if (isNegative) str[i++] = '-';
    str[i] = '\0';

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    return str;
}

#endif
