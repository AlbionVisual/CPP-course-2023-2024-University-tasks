#include <iostream>

using namespace std;

int main() {

	// ¬вести натуральное число n.ѕроверить, корректность ввода
	// числа, т.е. число не должно быть < 0 или равно 0, иначе повторить ввод.
	// ќпределить Ц введЄнное число простое или нет.

	int n;
	bool isPrime = true;

	cout << "Enter Natural number: "; cin >> n;

	while (n <= 0) {
		cout << "Valid input try again: "; cin >> n;
	}

	for (int i = 2; i <= n/2; i++) {
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	}

	if (isPrime) cout << "Your number is prime (Yes)";
	else cout << "Your number isn't prime (No)";

	return 0;
}