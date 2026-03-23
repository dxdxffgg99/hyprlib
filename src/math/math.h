#ifndef HYPERLIB_MATH_H
#define HYPERLIB_MATH_H

#include "../platform/hyprplatform.h"

/**
 * @brief Computes the fast inverse square root (1/√x).
 * @param number The input floating-point value.
 * @return The approximated inverse square root.
 */
static hypr_inline float Fast_Inverse_sqrt(float number);

/**
 * @brief Computes the fast square root (√x).
 * @param number The input floating-point value.
 * @return The approximated square root.
 */
static hypr_inline float Fast_sqrt(float number);

/**
 * @brief Returns the absolute value of a floating-point number.
 * @param f The input value.
 * @return The absolute value of f.
 */
static hypr_inline float Fast_abs(float f);

/**
 * @brief Performs addition of two 4D vectors (Vec4).
 * @param out Pointer to the result vector (float[4]).
 * @param a Pointer to the first operand vector (float[4]).
 * @param b Pointer to the second operand vector (float[4]).
 */
static hypr_inline void Vec4_Add(float* out, const float* a, const float* b);

/**
 * @brief Calculates the dot product of two 4D vectors (Vec4).
 * @param a Pointer to the first vector (float[4]).
 * @param b Pointer to the second vector (float[4]).
 * @return The computed dot product.
 */
static hypr_inline float Vec4_Dot(const float* a, const float* b);

/**
 * @brief Returns the greater of two floating-point values.
 * @param a The first value to compare.
 * @param b The second value to compare.
 * @return The maximum of a and b.
 */
static hypr_inline float Fast_max(float a, float b);

/**
 * @brief Returns the lesser of two floating-point values.
 * @param a The first value to compare.
 * @param b The second value to compare.
 * @return The minimum of a and b.
 */
static hypr_inline float Fast_min(float a, float b);

/**
 * @brief Determines the sign of a floating-point number.
 * @param f The input value.
 * @return 1.0 if positive, -1.0 if negative, or 0.0 if zero.
 */
static hypr_inline float Fast_sign(float f);

/**
 * @brief Computes the fast reciprocal (1/x) of a number.
 * @param f The input value.
 * @return The computed inverse.
 */
static hypr_inline float Fast_inv(float f);

/**
 * @brief Computes a fast approximation of the sine function.
 * @param x The input angle in radians.
 * @return The approximated sine of x.
 */
static hypr_inline float Fast_sin(float x);

#endif