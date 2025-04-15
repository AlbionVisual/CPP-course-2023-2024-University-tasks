#include <iostream>

using namespace std;

int countPals(int* arr, int n);						// ������� ������� ����������� � �������

int main() {

	// 2.	��������� �������, ������� ��� ����������� ������� �����������
	//		����� ����������, ������� � �� ���������-�����������.
	//		� ������� matr(n, m) ����� ������(������), ���������� ���������� 
	//		���������� ��������� - �����������, �������� ������� ������(��� 
	//		�������� ����� 0).��� ������������ ����� ������������ ������ 
	//		���������� �� ������.�������������� ������ �� ������������.

	//		5 5
	//		131    34    3223    52   4114
	//		2332  451  15451  672  617
	//		411    2992  521    72    288
	//		42      1331  155    413  513
	//		811    5445  166   118   32123	

	const short MAX = 20;

	int n, m; cout << "Enter size (x, y): "; cin >> m >> n;

	int arr[MAX][MAX];
	cout << "Enter array:\n";						// ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int* ptr[MAX];
	for (int i = 0; i < n; i++) ptr[i] = arr[i];

	short min = countPals(ptr[0], m), id = 0;
	for (int i = 1; i < n; i++) {
		if (countPals(ptr[i], m) < min) {
			id = i; min = countPals(ptr[i], m);		// ����� ������ ������
		}
	}
	id++;
	for (int i = n++; i > id; i--) {
		ptr[i] = ptr[i - 1];						// ��������������
	}
	ptr[id] = arr[n];
	for (int i = 0; i < m; i++) {
		ptr[id][i] = 0;
	}

	cout << "\nYour array:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ptr[i][j] << ' ';
		}											// �����
		cout << endl;
	}

	return 0;
}

bool isPalindrom(int num) {							// ��������� ��������� �� �����
	int temp = num, rev = 0;
	while (temp) {
		rev = rev * 10 + temp % 10;
		temp /= 10;
	}
	return rev == num;
}
int countPals(int* arr, int n) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (isPalindrom(arr[i])) {
			counter++;
		}
	}
	return counter;
}