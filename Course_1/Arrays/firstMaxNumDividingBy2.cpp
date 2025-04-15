#include <iostream>

using namespace std;

bool isEven(int);

int main() {

	// ������/������� ���������� ������ mas(n). ����� � ������� ������
	// ������������ ������� � ��� ������ ����� ������ ��������� �������.
	// ���� ������ ��������� ���, ������ ���������

	const int SIZE = 4;
	int arr[SIZE];
	int max, ind = -1;

	// ���� �������
	cout << "Enter your array: "; for (int i = 0; i < SIZE; i++) cin >> arr[i];

	for (int i = 0; i < SIZE; i++) { // ������� �������
		
		if (isEven(arr[i])) { // � ������ ���� ������� ������ ����� � ������ ��� max

			if (ind == -1) { // ���� ������ ������� ����������� �������
				max = arr[i];
				ind = i;
				continue;
			}

			if (arr[i] > max) { // ���� ������� ������� ������
				max = arr[i];
				ind = i;
			}
		}
	}

	// ����� ����������
	if (ind != -1) {
		cout << "Your element: " << arr[ind] << " and it's index: " << ind;
	}
	else cout << "There is no even numbers";


	return 0;
}

// �������� ����� �� ��������
bool isEven(int num) {
	if (num % 2 == 0)return true;
	else return false;
}