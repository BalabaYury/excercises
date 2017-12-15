#include "header.h"
double s3, s4, s41, s42, d3, d4, x, S2 = 0, C2;
extern double S1 = 0;
double int2(double a, double b, double c, double n) {
	x = a;
	d3 = fabs(a - b) / 2;
	d4 = d3 / 2;
	while (x < b) {
		if (sin(1 / x) < sin(1 / (x + d3))) {
			s3 = d3*sin(1 / x);
			S1 += s3;
			if (sin(1 / x) < sin(1 / (x + d4))) {
				s41 = d4*sin(1 / x);
			}
			else {
				s41 = d4*sin(1 / (x + d4));
			}
			if (sin(1 / (x + d4)) < sin(1 / (x + 2 * d4))) {
				s42 = d4*sin(1 / (x + d4));
			}
			else {
				s42 = d4*sin(1 / (x + 2 * d4));
			}
			s4 = s41 + s42;
			S2 += s4;
		}
		else {
			s3 = d3*sin(1 / (x + d3));
			S1 += s3;
			if (sin(1 / x) < sin(1 / (x + d4))) {
				s41 = d4*sin(1 / x);
			}
			else {
				s41 = d4*sin(1 / (x + d4));
			}
			if (sin(1 / (x + d4)) < sin(1 / (x + 2 * d4))) {
				s42 = d4*sin(1 / (x + d4));
			}
			else {
				s42 = d4*sin(1 / (x + 2 * d4));
			}
			s4 = s41 + s42;
			S2 += s4;
		}
		while (fabs(S1 - S2) > c) {
			S1 -= s3;
			S2 -= s4;
			d3 = d4;
			d4 = d4 / 2;
			if (sin(1 / x) < sin(1 / (x + d3))) {
				s3 = d3*sin(1 / x);
				S1 += s3;
				if (sin(1 / x) < sin(1 / (x + d4))) {
					s41 = d4*sin(1 / x);
				}
				else {
					s41 = d4*sin(1 / (x + d4));
				}
				if (sin(1 / (x + d4)) < sin(1 / (x + 2 * d4))) {
					s42 = d4*sin(1 / (x + d4));
				}
				else {
					s42 = d4*sin(1 / (x + 2 * d4));
				}
				s4 = s41 + s42;
				S2 += s4;
			}
			else {
				s3 = d3*sin(1 / (x + d3));
				S1 += s3;
				if (sin(1 / x) < sin(1 / (x + d4))) {
					s41 = d4*sin(1 / x);
				}
				else {
					s41 = d4*sin(1 / (x + d4));
				}
				if (sin(1 / (x + d4)) < sin(1 / (x + 2 * d4))) {
					s42 = d4*sin(1 / (x + d4));
				}
				else {
					s42 = d4*sin(1 / (x + 2 * d4));
				}
				s4 = s41 + s42;
				S2 += s4;
			}
		}
		x += d3;
	}
	C2 = fabs(S1 - S2);
	return S1;
}