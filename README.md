# excercises
/* Балаба Юрий, 4 семинар, 24 задача */
/*header.h*/
#ifndef mark
#define mark
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
extern double a, b, c, n, C1, C2;
double int1(double a, double b, double c, double n);
double int2(double a, double b, double c, double n);
#endif




/*main.cpp*/
#include "header.h"
int main() {
	cout << "enter a" << endl << flush;
	cin >> a;
	cout << "enter b" << endl << flush;
	cin >> b;
	cout << "enter quantity of divisions" << endl << flush;
	cin >> n;
	cout << "enter accuracy" << endl << flush;
	cin >> c;
	cout << "trapeze method: " << int1(a, b, c, n) << endl << flush;
	cout << "accuracy: " << C1 << endl << flush;
	cout << "low squares method: " << int2(a, b, c, n) << endl << flush;
	cout << "accuracy: " << C2 << endl << flush;
	system("pause");
	return 0;
}




/*int1.cpp*/
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





/*int2.cpp*/
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
