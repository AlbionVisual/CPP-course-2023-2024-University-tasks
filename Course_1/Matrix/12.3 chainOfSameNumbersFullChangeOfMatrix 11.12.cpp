#include <iostream>
using namespace std;

int longestChain(int[], int);						// �������� longestChain

int main() {

	// 3. � ������� ������� ��� ������, � ������� ��� ������� ������ ���������,
	//    ������� ������, �������� ��������� ������. ���������� ������
	//	  ����������� �� ����������� ������������ ���� ������� ������
	//    ���������, ������� ������, � �������.

	const int X = 30, Y = 30;

	int n, m; cout << "\nEnter size of your matrix (n, m): "; cin >> n >> m; cout << endl;
	int matr[Y][X];
	cout << "Enter your matrix:\n";
	for (int i = 0; i < n; i++)						// ���� �������
		for (int j = 0; j < m; j++)
			cin >> matr[i][j];

	cout << "\nYour matrix:\n";
	for (int i = 0; i < n; i++) {					// ����� �������
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << ' ';
		cout << endl;
	}

	for (int i = 0; i < n; i++) {					// ������� ��� ������ ��� ������� ������ �����
		if(longestChain(matr[i], m) == 1) {
			for (int j = i; j < n; j++) {
				for (int k = 0; k < m; k++) {
					matr[j][k] = matr[j + 1][k];
				}
			}
			n--;
			i--;
		}
	}

	for (int i = n-1; i >0; i--) {					// ��������� ������ �������
		for (int j = 0; j < i; j++) {
			if (longestChain(matr[j], m) > longestChain(matr[j + 1], m)) {
				for (int k = 0; k < m; k++) {
					int buff = matr[j][k];
					matr[j][k] = matr[j + 1][k];
					matr[j + 1][k] = buff;
				}
			}
		}
	}

	cout << "\nNew matrix:\n";
	for (int i = 0; i < n; i++) {					// ����� ����� �������
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << ' ';
		cout << endl;
	}

	return 0;
}

int longestChain(int arr[], int size) {				// ������� longestChain
	int counter = 1, max = 1, prev = arr[0];
	for (int i = 1; i < size; i++) {
		if (prev == arr[i]) {
			counter++;
		} else {
			if (max < counter) max = counter;
			counter = 1;
		}
		prev = arr[i];
	}
	if (max < counter) max = counter;
	return max;
}