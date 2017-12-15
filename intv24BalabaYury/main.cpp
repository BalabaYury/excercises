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