#include <iostream>
using namespace std;

const int SIZE = 30;				// ������������ ������ ������� / �������

int digitAmount(int);
bool isEvenDiagonal(int[][SIZE], int);
void matrixTranspose(int[][SIZE], int);
void output(int[][SIZE], int);


int main() {

	// 1. ������/������� ������ matr(n, n). ���� �� ������� ��������� �������
	//    (�������) ��� ��������� � ������ ����������� ����, �� ���������
	//    ���������������� ������� (�������). 

	int n; cout << "Enter size: "; cin >> n;				// ���� �������
	int matr[SIZE][SIZE];

	cout << "Enter Matrix (" << n << "x" << n << "):\n";
	for (int i = 0; i < n; i++) {							// ���� ������� 
		for (int j = 0; j < n; j++) {
			cin >> matr[i][j];
		}
	}

	cout << endl << endl;
	output(matr, n);										// �����
	cout << endl;

	if (isEvenDiagonal(matr, n)) {				// ���� ������������� �������, ��

		matrixTranspose(matr, n);						// ���������������� �������

		output(matr, n);									// �����

	} else {												// �����
		cout << "Diagonal isn't even-digit";
	}

	return 0;
}

int digitAmount(int num) {
	int counter = 0;
	while (num) {
		num /= 10;
		counter++;
	}
	return counter;
}
bool isEvenDiagonal(int matr[][SIZE], int n = SIZE) {
	for (int i = 0; i < n; i++) {
			if (digitAmount(matr[i][i]) % 2 != 0) return 0;
	}
	return 1;
}
void matrixTranspose(int matr[][SIZE], int n = SIZE) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int temp = matr[i][j];
			matr[i][j] = matr[j][i];
			matr[j][i] = temp;
		}
	}
}
void output(int matr[][SIZE], int n = SIZE) {
	for (int i = 0; i < n; i++) {				// ����� �������
		for (int j = 0; j < n; j++) {
			cout.width(6);		cout << matr[i][j];
		}
		cout << endl;
	}
}