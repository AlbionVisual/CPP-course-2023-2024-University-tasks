#include <iostream>

using namespace std;

bool containsHex(int);						// ����� � ������ ������� 16-�� ���� � �����
int maxDigit(int);							// ������������ ����� �����
int oldestDigit(int);						// ������� ����� �����

int main() {

	// 3.	��������� �������, ������� ��� ������ ������ ����� ����������,
	//		����  � ��� ������ 16-�� �����-����� (�.�. ����� A-F) ��� ���. 
	//		��� ��������� ���� ������������ ������� ��������.
	//		������ / ������� ������ ����� ����� mas(n).����� � ������� 
	//		������������ �������(������) ����� ���������, ������� �� 
	//		�������� �� ����� 16 - �� ����� - �����(A�F), �������� ����� ���
	//		�������� �����(��������), � ����������-- - ��������� � ��(� 
	//		������������ ��������) �������� ������������ ����� � ������� ��� 
	//		���.������ ���������.������������� ������, ���� � ������� ��� 
	//		���������, �� ���������� 16 - �� ���� - ����.
	


	int n; cout << "Enter array size: "; cin >> n;
	const int N = 100; int mass[N];

	cout << "Enter array:\n";
	for (int i = 0; i < n; i++)				// ����
		cin >> hex >> mass[i];

	int addence;
	cout << "Enter number to concatanate: "; cin >> hex >> addence;

	cout << endl;


	int id = -1, max_val;
	for (int i = 0; i < n; i++) {
		if (!containsHex(mass[i])) {
			if (id == -1) {
				id = i; max_val = mass[i];	// ����� �������������
			}
			else if (mass[i] > max_val) {
				id = i; max_val = mass[i];
			}
		}
	}

	if (id != -1) {

		for (int* i = &mass[n]; i >= &mass[id]; i--)		// ������� ��������
			*i = *(i - 1);

		mass[id] = addence; n++; id++;

		cout << "Your array: ";
		for (int i = 0; i < n; i++) {
			cout << hex << mass[i] << ' ';					// �����
		}

		if (maxDigit(mass[id]) == oldestDigit(mass[id])) cout << "\nMax element: " << mass[id] << " - Match.";
		else cout << "\nMax element: " << mass[id] << " - Don't match.";

	}
	else {
		cout << "No numbers with hex digits.";
	}

	cout << "\n\n";

	return 0;
}



bool containsHex(int num) {

	int eraser = 15;

	while (num != 0) {

		if ((num & eraser) >= 10)
			return 1;

		num = num >> 4;
	}

	return 0;
}


int maxDigit(int num) {
	int max = 0;

	while (num > 0) {

		if (num % 16 > max)
			max = num % 16;
	
		num /= 16;
	}
	return max;
}

int oldestDigit(int num) {

	while (num / 16 > 0) {
		num /= 16;
	}

	return num;
}