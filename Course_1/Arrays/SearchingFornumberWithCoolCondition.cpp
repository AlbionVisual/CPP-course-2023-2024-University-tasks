#include <iostream>
using namespace std;

int countingNumOfDigits(int num);

int main() {

	// Ввести/вывести одномерный массив mas(n). Найти в массиве элемент и
	// его индекс, сумма которого со следующим за ним элементом минимальна,
	// и в котором количество цифр чётное

	const int SIZE = 10;

	int searchedIndex;

	int mas[SIZE];

	cout << "Enter your array: "; for (int i = 0; i < SIZE; i++) cin >> mas[i];

	unsigned int min = 0; min--;

	for (int i = 0; i < SIZE - 1; i++) {
		if (mas[i] + mas[i + 1] < min && countingNumOfDigits(mas[i]) % 2 == 0) {
			searchedIndex = i;
		};
	}

	cout << "Your element: " << mas[searchedIndex] << " and it's index: " << searchedIndex;

	return 0;
}

int countingNumOfDigits(int num) {
	int counter = 0;

	while (num) {
		num /= 10;
		counter++;
	}

	return counter;
}