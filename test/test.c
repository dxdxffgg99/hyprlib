#include <stdio.h>

#include "../src/math/math.h"

static int g_failures = 0;

static int nearly_equal(float a, float b, float tolerance) {
	float diff = a - b;

	if (diff < 0.0f) {
		diff = -diff;
	}

	return diff <= tolerance;
}

static void check_true(int cond, const char *name) {
	if (!cond) {
		g_failures++;
		printf("[FAIL] %s\n", name);
		return;
	}

	printf("[PASS] %s\n", name);
}


static void test_fast_sqrt(void) {
	float value = 25.0f;
	float root = Fast_sqrt(value);

	check_true(nearly_equal(root, 5.0f, 0.05f), "Fast_sqrt(25) ~= 5");
}

int main(void) {
	printf("Running hyprlib smoke tests...\n");

	test_fast_sqrt();

	if (g_failures != 0) {
		printf("\nResult: %d test(s) failed.\n", g_failures);
		return 1;
	}

	printf("\nResult: all tests passed.\n");
	return 0;
}
