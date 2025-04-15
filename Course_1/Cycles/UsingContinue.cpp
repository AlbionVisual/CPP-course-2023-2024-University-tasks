// Пример 3. Найти произведение нечетных чисел из диапазона [n, m].
// Использовать оператор continue.
#include <iostream>
using namespace std;
int main() {
	int n, m;
	int result = 1;
	cout << "Enter n, m: ";	 cin >> n >> m;		// 4   9
	for (int i = n; i <= m; i++) {
		if (i % 2 == 0) continue;
		result = result * i;
	}
	cout << "result = " << result << endl;		// result = 315
}
