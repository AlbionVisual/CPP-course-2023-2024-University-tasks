#include <iostream>
using namespace std;

// Function definitions
int dividers(int);

// copied funcs
void arrInput(int arr[], int size) {
	for (int i = 0; i < size; i++) cin >> arr[i];
}
bool isPrime(int num) {
	for (int i = 0; i <= sqrt(num); i++) if (num % i == 0)return false;
	return true;
}

int main() {

	// 2. ��������� �������, ������� ��� ������ ������ ����� ����������,
	// ������� � ��� ������ ���� 'A' (� 16 - ��  �/�). 
	// � ���������� ������� ����������� ����� mas(n), ��������� ������������
	// �������, ����� ������� � ��� ������, ���������� ������������ ����������
	// ���� 'A' (� 16 - � � / �), � �������� ��� � ������ ���������
	// �������(mas[0]).���� � ������� ��������� � ������ 'A' ���, ������
	// ��������������� ���������.

	const int SIZE = 4;
	int arr[SIZE];
	int max = 0;

	cout << endl << "Input your array: "; arrInput(arr, SIZE);
	cout << "Your array: "; for (int i = 0; i < SIZE; i++) cout << arr[i] << ' '; cout << endl << endl;

	for (int i = 0; i < SIZE; i++) { // comparing numbers in array
		cout << "Number: " << arr[i] << ", it's primes: ";
		int sum = dividers(arr[i]);
		if (sum > max) max = sum;
		cout << ", it's sum: " << sum << endl;
	}

	cout << "\nMax sum is: " << max << endl;

	return 0;
}

int dividers(int num) { // returns sum of separate prime dividers
	int sum = 0, lastPrime = 0;
	while (num>1) {
		for (int i = 2; i <= num; i++) {
			if (num % i == 0) {
				cout << i << ' ';
				if (lastPrime != i) {
					sum += i; lastPrime = i;
				}
				num /= i;
				break;
			}
		}
	}
	return sum;
}