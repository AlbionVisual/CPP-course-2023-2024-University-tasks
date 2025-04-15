// Пример 6. Операция инкремента. Префиксная и постфиксная формы
// операции.
#include <iostream>
using namespace std;
int main() {
	int num = 10;
	cout << "num = " << num << endl;			// 10
	cout << "num = " << ++num << endl;				// 11
	cout << "num = " << num << endl;				// 11
	cout << "num = " << num++ << endl;				// 11
	cout << "num = " << num << endl;				// 12
	int x = 1, y = 2;
	int sum = x + y++;
	cout << "sum = " << sum << endl;				// 3
	cout << "x = " << x << " y = " << y << endl;			// x=1 y=3
	x = 1, y = 2;
	sum = ++x + y;
	cout << "sum = " << sum << endl;				// 4
	cout << "x = " << x << " y = " << ++y << endl;		// x=2 y=3
}
