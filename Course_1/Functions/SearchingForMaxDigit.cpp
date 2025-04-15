#include <iostream>
using namespace std;

int maxDigit(int);

int main() {

	// Ввести последовательно n натуральных чисел. Определить
	// количество чисел, максимальная цифра которых чётная.


	int n, restNum, counter = 0;
	cout << "Enter number of numbers: "; cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Enter number: "; cin >> restNum;
		if (maxDigit(restNum) % 2 == 0) counter++;
	}

	cout << "Number of max digits: " << counter;

	return 0;
}

int maxDigit(int num) {

	int max=0, restNum=num;

	while (restNum > 0) {
		if (restNum % 10 > max) max = restNum % 10;
		restNum /= 10;
	}

	return max;
}