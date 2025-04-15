#include <iostream>
using namespace std;

int avg(int[], int);						// �������� ������� avg

int main() {

	// 1. ������/������� ������ matr(n, m). ������ ������� (������),
	//	  ������� �������������� ������ ��������� ������� ����������,
	//    �������� ������� � ��������� ������� �������.


	const int X = 30, Y = 30;

	int n, m; cout << "\nEnter sizes of matrix (n, m): "; cin >> n >> m; cout << endl;
	int matr[Y][X];
	cout << "Enter your matrix:\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)			// ���� �������
			cin >> matr[i][j];

	cout << "\nYour matrix:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)			// ����� �������
			cout << matr[i][j] << ' ';
		cout << endl;
	}

	int max = avg(matr[0], m), ind = 0;		// ���� ������ � ������������ ������� ��������������
	for (int i = 1; i < n; i++) {
		if (max < avg(matr[i], m)) {
			max = avg(matr[i], m);
			ind = i;
		}
	}

	for (int i = 0; i < m; i++) {
		int buff = matr[ind][i];
		matr[ind][i] = matr[n - 1][i];		// ������ ������� ������
		matr[n - 1][i] = buff;
	}

	cout << "\n New matrix:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)			// ����� ��������� �������
			cout << matr[i][j] << ' ';
		cout << endl;
	}

	return 0;
}

int avg(int arr[], int size) {				// ������� avg
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];

	return sum / size;
}