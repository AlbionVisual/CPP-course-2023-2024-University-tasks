#include <iostream>
using namespace std;

int main() {

	// ¬вод числа и подсчЄт суммы и кол-ва всех его цифр
	
	int n, result, i = 0, sum = 0;
	cout << "Enter integer number: "; cin >> n;

	result = abs(n);
	// While there is more digits
	while (result > 0) {
		i = i + 1;
		sum = sum + result % 10;
		result = result / 10;
	}

	cout << "Digital sum: " << sum << endl << "Number of digits: " << i;

	return 0;
}