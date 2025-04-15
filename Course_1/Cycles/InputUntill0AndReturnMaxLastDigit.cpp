#include <iostream>
using namespace std;

int main() {

	// Ввести последовательно целые числа до первого нулевого
	// числа. Найти среди них число (первое) с максимальной младшей 
	// цифрой, запомнить его в переменной max


	int num, max=-1;

	cout << "Enter numbers: ";

	do {
		cin >> num;
		if (num % 10 > max) max = num % 10;
	} while (num != 0);

	cout << "The largest last digit is: " << max;


	return 0;
}