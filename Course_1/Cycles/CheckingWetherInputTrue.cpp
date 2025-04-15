// Пример 6. Ввести последовательно n целых чисел и найти их сумму.
// Использовать оператор for.
// При вводе n проверить корректность (правильность) его ввода.
#include <iostream>
using namespace std;
int main() {
	int n, num, sum = 0;
	do {							// проверка n
		cout << "Enter n: ";	cin >> n;
	} while (n < 0 || n == 0);
	for (int i = 1; i <= n; i = i + 1) {
		cout << "Enter number: ";	cin >> num;
		sum = sum + num;
	}
	cout << "sum =  " << sum << endl;
}
