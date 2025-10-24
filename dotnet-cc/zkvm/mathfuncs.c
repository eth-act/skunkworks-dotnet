#include "custom_shims.h"

/* Simplistic approximations of common math functions */

double copysign(double a, double b) {
	if ((a < 0 && b > 0) || (a > 0 && b < 0)) return -a;
	return a;
}

double ceil(double x) {
	return (double) (int) x+1;
}

float ceilf(float x) {
	return (float) (int) x+1;
}

double nearbyint(double x) {
	return (double) (int) x;
}

float nearbyintf(float x) {
	return (float) (int) x;
}

double floor(double x) {
	return (double) (int) x;
}

float floorf(float x) {
	return (float) (int) x;
}

double trunc(double x) {
	return floor(x);
}

float truncf(float x) {
	return floorf(x);
}

// fast-integer sqrt
double sqrt(double x) {
	unsigned int a, b;
	unsigned int val = (int)x;

	if (val < 2) return x;

	a = 1255;

	b = val / a; a = (a+b)/2;
	b = val / a; a = (a+b)/2;
	b = val / a; a = (a+b)/2;
	b = val / a; a = (a+b)/2;

	return (double) a;
}
