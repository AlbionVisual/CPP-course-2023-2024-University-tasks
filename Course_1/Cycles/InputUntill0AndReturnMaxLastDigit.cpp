#include <iostream>
using namespace std;

int main() {

	// ������ ��������������� ����� ����� �� ������� ��������
	// �����. ����� ����� ��� ����� (������) � ������������ ������� 
	// ������, ��������� ��� � ���������� max


	int num, max=-1;

	cout << "Enter numbers: ";

	do {
		cin >> num;
		if (num % 10 > max) max = num % 10;
	} while (num != 0);

	cout << "The largest last digit is: " << max;


	return 0;
}