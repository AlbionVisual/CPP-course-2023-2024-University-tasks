#include <iostream>
using namespace std;

int main() {

	double a, b;
	double x;

	cout << "Enter a and b (ax=b): "; cin >> a >> b;

	if (a == 0) {
		if (b == 0) {
			cout << "X might be equal to any number" << endl;
		}
		else {
			cout << "There is no X that solves this equotation" << endl;
		}
	}
	else {
		x = b / a;
		cout << "X = " << x << endl;
	}


	return 0;
}