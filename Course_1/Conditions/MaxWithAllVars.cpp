#include <iostream>
using namespace std;

int main() {
	// Вывести сначала большее чисо, а затем остальные
	int a, b, c, max, m1, m2;
	cout << "Enter 3 numbers: "; cin >> a >> b >> c;

	max = a;
	m1 = b;
	m2 = c;
	if (b > max) {
		max = b;
		m1 = a;
		m2 = c;
	}
	else if (c > max) { 
		max = c;
		m1 = a;
		m2 = b;
	};

	cout << "Max is: " << max << ", others is: " << m1 << " and " << m2;
}

/*

	int a, b, c;
	cout << "Enter 3 numbers: "; cin >> a >> b >> c;

	if (a >= b && a >= c)
		cout << "Max a: " << a << ", others b and c: " << b << ", " << c;
	if (b >= a && b >= c)
		cout << "Max b: " << b << ", others a and c: " << a << ", " << c;
	if (c >= b && c >= a)
		cout << "Max c: " << c << ", others a and b: " << a << ", " << b;

	Краткосрочное решение

*/