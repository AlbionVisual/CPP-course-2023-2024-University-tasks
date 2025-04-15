#include <iostream>
using namespace std;

int main() {
	// –асположить 4 числа в пор€дке возрастани€

	int a, b, c, d, buff;
	
	cout << "Enter 4 numbers: "; cin >> a >> b >> c >> d;

	// No order
	if (a > b) { buff = a; a = b; b = buff; }
	if (b > c) { buff = c; c = b; b = buff; }
	if (c > d) { buff = c; c = d; d = buff; }
	// Last is the biggest
	if (a > b) { buff = a; a = b; b = buff; }
	if (b > c) { buff = c; c = b; b = buff; }
	// Last 2 is in order
	if (a > b) { buff = a; a = b; b = buff; }
	// All are in order

	cout << "Numbers in order: " << a << ' ' << b << ' ' << c << ' ' << d;

	return 0;
}