// Пример 2. Ввести последовательно числа до первого отрицательного или
// нулевого числа. Вывести на консоль первое введённое отрицательное число
// или выдать сообщение "No", если отрицательное число не ввели.
#include <iostream>
using namespace std;
int main() {
	int n, num;
	bool flag = 0;
	do {
		cout << "Enter  number: ";  cin >> num;
		if (num < 0) { flag = 1; break; }
	} while (num);
	if (flag) cout << "num = " << num << endl;
	else cout << "No" << endl;
}
