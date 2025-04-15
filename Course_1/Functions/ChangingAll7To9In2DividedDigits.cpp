#include <iostream>
using namespace std;

int numOfDigits(int);
void changeAll7To9(int&);

int main() {

	// Ввести последовательно натуральные числа до первогонулевого числа.
	// В каждом числе, количество цифр которого чётное, заменить все цифры 7
	// на цифры 9.

	int n;
	
	do {
		cout << "Enter n: "; cin >> n;
		if (n) {
			if (numOfDigits(n) % 2 == 0) {
				changeAll7To9(n);
			}
		}
		cout << "Your num: " << n << endl;
	} while (n);

	

	return 0;
}

int numOfDigits(int num) {
	int count = 0;

	while (num) {
		num /= 10;
		count++;
	}

	return count;
}

void changeAll7To9(int& num) {
	int buff = 0;
	while (num) {
		buff *= 10;
		if (num % 10 == 7) buff += 9;
		else buff += num % 10;
		num /= 10;
	}

	while (buff) {
		num *= 10;
		num += buff % 10;
		buff /= 10;
	}
}