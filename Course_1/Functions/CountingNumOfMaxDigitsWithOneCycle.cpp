#include <iostream>
using namespace std;

int counting(int);

int main() {

	// ������ ����������� ����� n. ����������, ������� ��� � ��
	// ����������� ������������ �����.

	int n;
	cout << "Enter number: "; cin >> n;
	// cout << n << endl; // wether not big enough

	cout << "Nuber of max digits: " << counting(n);

	return 0;
}

int counting(int num) {

	int max = 0, count = 0;

	while (num) {
		if (max < num % 10) {
			max = num % 10;
			count = 1;
		}
		else if (max == num % 10) {
			count++;
		}
		num /= 10;
	}

	return count;
}