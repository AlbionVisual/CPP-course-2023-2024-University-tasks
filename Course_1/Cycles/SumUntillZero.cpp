#include <iostream>
using namespace std;
int main() {
	int num, sum = 0;

	do {
		cout << "Enter number: ";	cin >> num;
		sum = sum + num;
	} while (num != 0);
	cout << "sum =  " << sum << endl;
}
