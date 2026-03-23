# HYPRLIB

A lightweight, portable C library providing fast math utilities, sorting algorithms, and cross-platform detection macros. Compatible with C89 through C23.

## Features

- **Platform Detection** — Compiler, OS, CPU, and C standard version detection macros
- **Fast Math** — Optimized math functions including fast inverse square root, square root, sine, and 4D vector operations
- **Sorting Algorithms** — Multiple sort implementations for different use cases
- **Utility Macros** — `swap`, `itoa`, `hypr_inline`, `hypr_restrict`, and more

## Building

```sh
mkdir build && cd build
cmake ..
cmake --build .
```

This produces a shared library (`hyperlib`).

### Running Tests

Tests are compiled against all supported C standards (C90, C99, C11, C17, C23):

```sh
ctest
```

## Usage

Include the single top-level header to pull in everything:

```c
#include "core.h"
```

Or include individual modules as needed:

```c
#include "src/math/math.h"
#include "src/algorithm/algo.h"
#include "src/platform/platform.h"
```

## Modules

### Platform (`src/platform/`)

Compile-time detection macros for writing portable code.

| Header | Purpose |
|---|---|
| `compiler.h` | Detects GCC, Clang, or MSVC |
| `os.h` | Detects Linux, macOS, Windows, BSD variants |
| `cstdver.h` | Detects active C standard (C89–C23) |
| `cpu.h` | CPU architecture detection |
| `types.h` | Validates fixed-width type sizes at compile time |
| `platform.h` | Aggregates all of the above; defines `hypr_inline`, `hypr_restrict`, `hypr_unused` |

Example:

```c
#if HYPERLIB_COMPILER_GCC
    // GCC-specific code
#endif

#if HYPR_C11
    // C11-specific code
#endif
```

### Math (`src/math/`)

Fast, inline floating-point math functions.

| Function | Description |
|---|---|
| `Fast_Inverse_sqrt(x)` | Fast inverse square root (1/√x) |
| `Fast_sqrt(x)` | Fast square root approximation |
| `Fast_abs(x)` | Absolute value |
| `Fast_inv(x)` | Fast reciprocal (1/x) |
| `Fast_sin(x)` | Fast sine approximation (radians) |
| `Fast_max(a, b)` | Returns the greater of two floats |
| `Fast_min(a, b)` | Returns the lesser of two floats |
| `Fast_sign(x)` | Returns 1.0, -1.0, or 0.0 |
| `Vec4_Add(out, a, b)` | Adds two `float[4]` vectors |
| `Vec4_Dot(a, b)` | Dot product of two `float[4]` vectors |

### Algorithm (`src/algorithm/`)

Sorting functions operating on `int` arrays.

| Function | Time Complexity | Notes |
|---|---|---|
| `Quick_sort(arr, n)` | O(n log n) avg | Best general-purpose sort for large data |
| `Merge_sort(arr, n)` | O(n log n) | Stable; requires O(n) extra space |
| `Heap_sort(arr, n)` | O(n log n) | In-place, not stable |
| `Shell_sort(arr, n)` | O(n log² n) | Improved insertion sort |
| `Insertion_sort(arr, n)` | O(n²) | Efficient for small (n < 16) or nearly sorted arrays |
| `Counting_sort(arr, n, max_val)` | O(n + k) | Non-comparative; best when value range is small |
| `Radix_sort(arr, n)` | O(nk) | Digit-by-digit sort |
| `Selection_sort(arr, n)` | O(n²) | Minimizes swaps |
| `Bubble_sort(arr, n)` | O(n²) | Educational use |

### Utilities (`core.h`)

```c
// Swap any two variables of the same type (GCC/Clang extension)
swap(a, b);

// Convert integer to string
char buf[32];
itoa(42, buf, 10);   // decimal
itoa(255, buf, 16);  // hex
```

## Supported Platforms

| Compiler | OS | C Standard |
|---|---|---|
| GCC | Linux | C89, C90, C99, C11, C17, C23 |
| Clang | macOS | C89, C90, C99, C11, C17, C23 |
| MSVC | Windows (32/64-bit) | C89, C90, C99, C11, C17, C23 |
| — | FreeBSD, NetBSD, OpenBSD | — |

## License

This project does not currently include a license file. All rights reserved by the author unless otherwise stated.
