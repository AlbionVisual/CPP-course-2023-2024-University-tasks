#include <iostream>
using namespace std;

int main() {

	const int MIN = 1, MAX = 4;
	int num;
	cout << "Input your number: "; cin >> num;

	if (num >= MIN) {
		if (num <= MAX) {
			cout << "Gap contains X: True" << endl;
		}
		else {
			cout << "Gap doesn`t contain X" << endl;
		}
	}

	return 0;
}