#include <iostream>
using namespace std;

bool isPrime(int);
int countDigits(int);

int main() {

	// Ввести последовательно n натуральных чисел.  Найти среди
	// них первое простое число с максимальным количеством цифр.

	int n, numOfDigits = 0, maxPrime = 0, num;
	cout << "Enter number of numbers: "; cin >> n;



	for (int i = 0; i < n; i++) {
		cout << "Enter number: "; cin >> num;
		if (isPrime(num) && countDigits(num) > numOfDigits) {
			numOfDigits = countDigits(num);
			maxPrime = num;
		}
	}

	cout << "First prime num with max amount of digits: " << maxPrime;
	
	return 0;
}

bool isPrime(int num) {
	
	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0) return false;
	}

	return true;
}

int countDigits(int num) {

	int counter = 0;

	while (num) {
		counter++;
		num /= 10;
	}

	return counter;
}