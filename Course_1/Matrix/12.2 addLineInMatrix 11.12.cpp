#include <iostream>
using namespace std;

bool isEven(int);							// �������� isEven
int firstDigit(int);						// �������� firstDigit
int maxDigit(int);							// �������� maxDigit
int count(int[], int);						// �������� count

int main() {

	// 2. ������/������� ������ matr(n, m). � ������� ����� ������
	//    (������) � ������������ ����������� ����� ���������,
	//    �������� ������� ������ (��� �������� ����� ����).

	const int X = 30, Y = 30;

	int n, m; cout << "\nEnter size of your matrix (n, m): "; cin >> n >> m; cout << endl;
	int matr[Y][X];
	cout << "Enter your matrix:\n";
	for (int i = 0; i < n; i++)				// ���� �������
		for (int j = 0; j < m; j++)
			cin >> matr[i][j];

	cout << "\nYour matrix:\n";
	for (int i = 0; i < n; i++) {			// ����� �������
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << ' ';
		cout << endl;
	}

	int max = count(matr[0], m), ind = 0;
	for (int i = 0; i < n; i++)				// ���� ������ ������
		if (max < count(matr[i], m)) {
			max = count(matr[i], m);
			ind = i;
		}

	for (int i = n; i > ind + 1; i--) {		// ������������ ��� ������ ����
		for (int j = 0; j < m; j++) {
			matr[i][j] = matr[i - 1][j];
		}
	} n++;

	for (int i = 0; i < m; i++)				// ������� ������
		matr[ind+1][i] = 0;

	cout << "\nNew matrix:\n";
	for (int i = 0; i < n; i++) {			// ����� ����� �������
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << ' ';
		cout << endl;
	}

	return 0;
}

bool isEven(int num) {						// ������� isEven
	if (num % 2) return false;
	return true;
}
int maxDigit(int num) {						// ������� maxDigit
	int max = 0;
	while (num) {
		if (max < num % 10) max = num % 10;
		num /= 10;
	}
	return max;
}
int firstDigit(int num) {					// ������� firstDigit
	while (num / 10) {
		num /= 10;
	}
	return num;
}
int count(int arr[], int size) {			// ������� count
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (isEven(maxDigit(arr[i]) - firstDigit(arr[i]))) counter++;
	}
	return counter;
}