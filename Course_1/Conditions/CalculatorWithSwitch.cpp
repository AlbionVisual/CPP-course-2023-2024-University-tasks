#include <iostream>
using namespace std;

int main() {

	int a, b, result;
	bool passed = true;
	char operation;

	cout << "Enter 2 numbers: "; cin >> a >> b;
	cout << "Enter operation (*, /, + or -): "; cin >> operation;


	switch (operation) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = (a * b);
		break;
	case '/':
		if (b) result = a / b;
		else { cout << "Don't divide by 0!"; passed = false; }
		break;
	default:
		cout << "Unknown operation!";
		passed = false;
	}
	if (passed) cout << a << ' ' << operation << ' ' << b << " = " << result;


	return 0;
}