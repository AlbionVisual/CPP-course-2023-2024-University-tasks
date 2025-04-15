// Пример 4. Вывести на экран три строки  цифр от 0 до 9.
// Использовать цикл for.
#include <iostream>
using namespace std;
int main() {
	int i, j;
	for (i = 1; i <= 3; i++) {				// внешний цикл
		for (j = 0; j < 10; j++)			// внутренний цикл
			cout << j << ' ';
		cout << endl;
	}
}
