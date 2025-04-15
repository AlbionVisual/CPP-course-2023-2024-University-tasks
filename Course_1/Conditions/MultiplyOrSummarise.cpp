#include<iostream>
using namespace std;

int main() {

	int a, b, res;

	cout << "Enter a and b: "; cin >> a >> b;

	if (a > 0 && b > 0) {
		res = a * b;
		cout << "a * b = "<<res << endl;
	}
	else {
		res = a + b;
		cout << "a + b = " << res << endl;
	}

	return 0;
}