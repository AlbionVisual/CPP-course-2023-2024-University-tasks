#include <iostream>
using namespace std;

int countEqualDigitsInRow(int);
void changeFirstWithLastDigit(int&);

int main() {

	// Ввести последовательно n натуральных чисел. В каждом числе,
	// содержащем последовательность из k (вводится пользователем)
	// одинаковых цифр стоящих подряд, переставить местами старшую
	// и младшую цифры (в том же числе). 

	int n, k, num;
	cout << "Enter amount of numbers (n>0): "; cin >> n;
	cout << "Enter amount of digits in a row (k>1): "; cin >> k;

	for (int i = 0; i < n; i++) {
		cout << "Enter number: "; cin >> num;
		if (countEqualDigitsInRow(num) >= k) {
			changeFirstWithLastDigit(num);
		}
		cout << "Number after function: " << num << endl;
	}

	return 0;
}

int countEqualDigitsInRow(int num) {
	int prev = num % 10, max = 1, counter = 1;
	num /= 10;
	while (num > 0) {
		if (prev == num % 10) counter++;
		else {
			if (max < counter) max = counter;
			counter = 1;
		}
		prev = num % 10;
		num /= 10;
	}
	cout << max << endl;
	return max;
};

void changeFirstWithLastDigit(int& num) {
	int newNum = num, firstDigit = 0, counter=0;

	while (num) {
		firstDigit = num % 10;
		num /= 10;
		counter++;
	}

	int tens = 1;
	counter--;
	while (counter) {
		tens *= 10;
		counter--;
	}

	newNum -= tens * firstDigit;
	newNum += tens * (newNum % 10);
	newNum /= 10;
	newNum *= 10;
	newNum += firstDigit;

	num = newNum;

}

