#include <iostream>
using namespace std;

int max_in_row(char [], int , char  = '*');

int main() {

	// 1. Найти в заданном символьном массиве (строке) максимальное
	// количество звёздочек, стоящих подряд.

	const int SIZE = 30;

	char str[SIZE];
	cout << "Enter your sentence: ";
	cin.get(str, SIZE);
	// cout << str << endl;

	cout << max_in_row(str, strlen(str)); // counting amount of * in a row

	return 0;
}

int max_in_row(char str[], int size, char sym) {
	int max = 0, counter = 0;
	for (int i = 1; i < size; i++) { // Checking all array
		if (str[i] == sym)counter++; // when meeting symbol
		else counter = 0;
		if (counter > max) max = counter; // when counter is greater than max amount
	}
	return max;
}