#include "header.h"
double s1, s2, d1, d2, y, I2 = 0, a, b, c, n, C1;
extern double I1 = 0;
double int1(double a,double b,double c,double n) {
	y = a;
	d1 = fabs(a - b) / n;
	d2 = d1 / 2;
	while (y < b) {
		s1 = d1 / 2 * (sin(1 / y) + sin(1 / (y + d1)));
		s2 = d2 / 2 * (sin(1 / y) + 2 * sin(1 / (y + d2)) + sin(1 / (y + 2 * d2)));
		I1 += s1;
		I2 += s2;
		while (fabs(I1 - I2) > c) {
			I1 -= s1;
			I2 -= s2;
			d1 = d2;
			d2 = d2 / 2;
			s1 = d1 / 2 * (sin(1 / y) + sin(1 / (y + d1)));
			s2 = d2 / 2 * (sin(1 / y) + 2 * sin(1 / (y + d2)) + sin(1 / (y + 2 * d2)));
			I1 += s1;
			I2 += s2;
		}
		y += d1;
	}
	C1 = fabs(I1 - I2);
	return I1;
}