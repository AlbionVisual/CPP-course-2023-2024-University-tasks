#include <iostream>

using namespace std;

int countAvg(int* arr, int n);							// ������� �������������� ������������� �����

int main() {

	// 1.	��������� �������, ������� ��� ����������� ������� 
	// 		����� ����� ������� ������� �������������� �������������
	// 		���������. � ������, ���� � ������� ��� ������������� ���������, ������� ���������� 0.
	// 		� ������� mas(n, m), ��������� ������������ �������, ����� ����� ������ (������),
	// 		������� �������������� ������������� ��������� ������� �������� ����������, � ��������
	// 		� ������� � ������ ������� (� �������� 0). ��� ������������ ����� ������������ ������
	// 		���������� �� ������. �������������� ������ �� ������������.

	const short int BORDER = 25;
	int n, m; cout << "Enter size (x, y): "; cin >> m >> n;

	int arr[BORDER][BORDER];
	cout << "Enter matrix:\n";
	for (int i = 0; i < n; i++) {								// ����
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int maxAvg = countAvg(arr[0], m), ind = 0;
	for (int i = 1; i < n; i++) {
		if (countAvg(arr[i], m) > maxAvg) {
			ind = i; maxAvg = countAvg(arr[i], m);			// ���� ������������ �������
		}
	}

	int* ptrArr[BORDER];
	for (int i = 0; i < n; i++) {
		ptrArr[i] = arr[i];
	}

	int* p = ptrArr[0];
	ptrArr[0] = ptrArr[ind];									// ������ �������
	ptrArr[ind] = p;

	cout << "\nYour matrix:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ptrArr[i][j] << ' ';						// �����
		}
		cout << endl;
	}
	return 0;
}

int countAvg(int* arr, int n) {
	int sum = 0, count = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			sum += arr[i];
			count += 1;
		}
	}

	return count != 0 ? sum / count : 0;
}