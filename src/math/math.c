#include "../platform/hyprplatform.h"
#include <math.h>

#if (CPU_ARCH_I386) || (CPU_ARCH_X86_64)
    #include <immintrin.h>
#elif (CPU_ARCH_AARCH64) || (CPU_ARCH_ARM64)
    #include <arm_neon.h>
#elif (CPU_ARCH_PPC64)
    #include <altivec.h>
#elif (CPU_ARCH_AVR)
    #include <avr/pgmspace.h>
#endif

static hypr_inline float Fast_Inverse_sqrt(float number) {
#if (CPU_ARCH_I386) || (CPU_ARCH_X86_64)
    float out;
    _mm_store_ss(&out, _mm_rsqrt_ss(_mm_set_ss(number)));
    return out;
#elif (CPU_ARCH_AARCH64) || (CPU_ARCH_ARM64)
    return vgetq_lane_f32(vrsqrteq_f32(vdupq_n_f32(number)), 0);
#elif (CPU_ARCH_PPC64)
    vector float v = {number, 0.0f, 0.0f, 0.0f};
    return vec_extract(vec_rsqrte(v), 0);
#else
    union { float f; int i; } conv;
    float x2 = number * 0.5F;
    conv.f = number;
    conv.i = 0x5f3759df - (conv.i >> 1);
    conv.f = conv.f * (1.5F - (x2 * conv.f * conv.f));
    return conv.f;
#endif
}

static hypr_inline float Fast_sqrt(float number) {
#if (CPU_ARCH_I386) || (CPU_ARCH_X86_64)
    float out;
    _mm_store_ss(&out, _mm_sqrt_ss(_mm_set_ss(number)));
    return out;
#elif (CPU_ARCH_AARCH64) || (CPU_ARCH_ARM64)
    return vgetq_lane_f32(vsqrtq_f32(vdupq_n_f32(number)), 0);
#else
    union { float f; int i; } conv;
    conv.f = number;
    conv.i = 0x1fbd1df5 + (conv.i >> 1);
    conv.f = 0.5f * (conv.f + number / conv.f);
    return conv.f;
#endif
}

static hypr_inline void Vec4_Add(float* out, const float* a, const float* b) {
#if (CPU_ARCH_I386) || (CPU_ARCH_X86_64)
    _mm_storeu_ps(out, _mm_add_ps(_mm_loadu_ps(a), _mm_loadu_ps(b)));
#elif (CPU_ARCH_AARCH64) || (CPU_ARCH_ARM64)
    vst1q_f32(out, vaddq_f32(vld1q_f32(a), vld1q_f32(b)));
#else
    for (int i = 0; i < 4; i++) out[i] = a[i] + b[i];
#endif
}

static hypr_inline float Vec4_Dot(const float* a, const float* b) {
#if (CPU_ARCH_I386) || (CPU_ARCH_X86_64)
    __m128 res = _mm_dp_ps(_mm_loadu_ps(a), _mm_loadu_ps(b), 0xF1);
    return _mm_cvtss_f32(res);
#elif (CPU_ARCH_AARCH64) || (CPU_ARCH_ARM64)
    return vaddvq_f32(vmulq_f32(vld1q_f32(a), vld1q_f32(b)));
#else
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
#endif
}

static hypr_inline float Fast_abs(float f) {
    union { float f; unsigned int i; } conv;
    conv.f = f;
    conv.i &= 0x7fffffff;
    return conv.f;
}

static hypr_inline float Fast_max(float a, float b) {
    return a > b ? a : b;
}

static hypr_inline float Fast_min(float a, float b) {
    return a < b ? a : b;
}

static hypr_inline float Fast_sign(float f) {
    union { float f; unsigned int i; } conv;
    conv.f = f;
    conv.i = (conv.i & 0x80000000) | 0x3f800000;
    return conv.f;
}

static hypr_inline float Fast_inv(float f) {
    union { float f; int i; } conv;
    conv.f = f;
    conv.i = 0x7ee43535 - conv.i;
    return conv.f;
}

static hypr_inline float Fast_sin(float x) {
    const float B = 1.27323954f;
    const float C = -0.40528473f;
    float y = B * x + C * x * (x < 0 ? -x : x);
    const float P = 0.225f;
    return P * (y * (y < 0 ? -y : y) - y) + y;
}