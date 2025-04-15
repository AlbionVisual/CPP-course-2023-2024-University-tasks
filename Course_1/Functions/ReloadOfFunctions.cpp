// Пример 7. Перегрузка функций для нахождения суммы двух целых чисел,
// трёх целых чисел, двух вещественных чисел.
// В программе не используется прототипы функций!!!
#include <iostream>
using namespace std;
int sum(int a, int b) { return a + b; }
int sum(int a, int b, int c) { return a + b + c; }
float sum(float a, float b) { return a + b; }
int main() {
	int x, y, z;
	float p, q;
	cout << "Enter int-chisla x, y, z: ";	cin >> x >> y >> z;
	cout << "Enter float-chisla p, q: ";	cin >> p >> q;
	cout << "x + y = " << sum(x, y) << endl;
	cout << "x + y + z = " << sum(x, y, z) << endl;
	cout << "p + q = " << sum(p, q) << endl;
}
