#include <iostream> 

using namespace std;

int main() {
	
	double a, b, res;
	char oper;
	cout << "Enter two numbers: "; cin >> a >> b;

	cout << "Enter operator: "; cin >> oper;

	if (oper == '+') {
		res = a + b;
		cout << a << " + " << b << " = " << res;
	}
	else if (oper == '*') {
		res = a * b;
		cout << a << " * " << b << " = " << res;
	}
	else if (oper == '-') {
		res = a - b;
		cout << a << " - " << b << " = " << res;
	}
	else if (oper == '/') {
		if (b != 0) {
			res = a / b;
			cout << a << " / " << b << " = " << res;
		}
		else cout << "Second value cannot be equal to 0";
	}
	else {
		cout << "Operator invalid";
	}

	return 0;
}