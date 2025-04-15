#include <iostream>
using namespace std;

bool isInSequence(int);

int main() {

	// Ввести последовательно n натуральных чисел.
	// Определить количество чисел, цифры которых образуют
	// возрастающую последовательность.

	int n, num, counter = 0;
	cout << "Enter number of numbers: "; cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Enter number: "; cin >> num;
		if (isInSequence(num)) counter++;
	}

	cout << "Number of numbers with sequence: " << counter;

	return 0;
}

bool isInSequence(int num) {

	int prevNum = num % 10; num /= 10;

	while (num > 0) {
		if (num % 10 >= prevNum) return false;
		num /= 10;
	}

	return true;

}