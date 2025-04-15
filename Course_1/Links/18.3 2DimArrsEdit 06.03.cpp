#include <iostream>

using namespace std;

int countingPairs(int* arr, int n);					// ��������� ���-�� ���

int main() {

	// 3.	��������� �������, ������� ��� ����������� ������� ����� �����
	//		���������� ���������� ��� �������� ���������, � ������� ������� 
	//		����� ����������.
	//		� ������� mas(n, m) (m�������), ��������� �������, � ������ ������
	//		���������� ���������� ��� �������� ���������, � ������� �������
	//		����� ����������, � ������� ������, ���������� ������ ����������
	//		����� ���.��� ������������ ����� ������������ ������ ���������� ��
	//		������.�������������� ������ �� ������������.

	//		4 4
	//		123 234 245 345
	//		3453 3 356 456
	//		1453 1 1534 145
	//		2 4 536 7347

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

	for (int i = 0; i < n; i++) {
		if (countingPairs(ptr[i], m) % 2 == 0) {
			n--;
			for (int j = i; j < n; j++) {
				ptr[j] = ptr[j + 1];
			}										// ��������������
			i--;
		}
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

int firstDigit(int n) {								// ���� ������ ����� �����
	while (n > 9) n /= 10;
	return n;
}

int countingPairs(int* arr, int n) {
	short counter = 0;
	for (int* p = arr; p < &arr[n]; p++) {
		if (firstDigit(*p) == firstDigit(*(p + 1))) {
			counter++;
			p++;
		}
	}
	return counter;
}