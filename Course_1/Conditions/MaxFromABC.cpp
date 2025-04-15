#include <iostream>
using namespace std;

int main() {
	// Вывести максимальное из 3 чисел

	int a, b, c, max;
	cout << "Enter 3 numbers: "; cin >> a >> b >> c;
	max = a;

	if (b > max) max = b;
	if (c > max) max = c;

	cout << "Max number: " << max;
}