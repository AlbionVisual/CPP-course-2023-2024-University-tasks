#include <iostream>

using namespace std;

int countHexDigits(int);								// ������� ���-�� 16-�� ���� �����

int main() {

	// 2.	��������� �������, ������� ��� ������ ������ ����� ����������, 
	//		������� � ��� ������ 16 - �� ���� - ����(�.�.����� A - F).��� 
	//		��������� ���� ������������ ������� ��������.
	//		������ / ������� ������ ����� ����� mas(n).����� ����� ��������� 
	//		�������, ������� �������� 16 - �� ����� - ����� ������ 
	//		�������(��� ������ � ��� �������) ���������� ������������
	//		���������� 16 - �� ���� - ����, � ������� ���.������������� 
	//		������, ���� � ������� ��� ���������, ������� �������� 16 - ��
	//		����� - �����.�������������� ������ �� ������������.

	int n; const int N = 100; int mass[N];
	cout << "Enter array size: "; cin >> n;
	
	cout << "Enter your array:\n";						// ����
	for (int i = 0; i < n; i++) {
		cin >> hex >> mass[i];
	}

	int maxAmount = 0;
	int id = -1;
	for (int i = 0; i < n; i++) {						// ���� ������������
		if (countHexDigits(mass[i]) > maxAmount) {
			maxAmount = countHexDigits(mass[i]);
			id = i;
		}
	}



	if (id != -1) {										// ���� ���� ��������
		for (int* i = &mass[id]; i != &mass[n-1]; i++) 				// ������� 1�� ������������
			*i = *(i + 1);

		n--;

		for (int i = 0; i < n; i++) {
			cout << hex << mass[i] << ' ';
		}
	}
	else {
		cout << "Your array doesn't have any numbers with hex digits.";
	}

	

	return 0;
}

int countHexDigits(int num) {
	
	int counter = 0, eraser = 15;

	while (num != 0) {

		if ((num & eraser) >= 10)
			counter++;

		num = num >> 4;
	}

	return counter;
}