#include <iostream>
using namespace std;

int main() {
	int num, remain, tens, digitAmount = 0;
	bool isValid = true;
	cout << "Enter your number: "; cin >> num;
	cout << "Inputed number is: " << num << endl;

	// Counting number of digits:
	remain = num;

	while (remain > 0) {
		digitAmount++;
		remain /= 10;
	}

	// Searching for non polindrom digits
	for (int k = 1; digitAmount - 2 * k >= 0; k++) {

		tens = 10;
		for (int i = 0; i < digitAmount - 2 * k; i++)
			tens *= 10;

		if (num % 10 != (num / tens) % 10) {
			isValid = false;
			break;
		}
		num /= 10;
	}

	if (isValid) cout << "Your number is Polindrom (Yes)";
	else cout << "Your number isn't Polindrom (No)";

	return 0;
}