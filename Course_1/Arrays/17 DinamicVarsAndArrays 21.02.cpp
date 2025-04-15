#include <iostream>

using namespace std;

int main() {

	int* ptr;
	// ptr = new int; // �������� 4 ����� ������, ������� ����� ���, ������ ���������
	// �������� new ����������� ��������� ������ �� ���� ���������� ���������
	// � �� ����������

	// ��� ���:
	ptr = new int(5); // ��������� 5 � �������������� ������

	// cout << *ptr;

	delete ptr;
	// � delete - ����������� ������

	int val1 = 10, val2 = 20;
	ptr = new int(val1);
	cout << "val1 = " << val1 << endl;
	cout << "*ptr = " << *ptr << endl;
	val1 = 5;
	cout << "val1 = " << val1 << endl;
	cout << "*ptr = " << *ptr << endl;
	*ptr = 7;
	cout << "val1 = " << val1 << endl;
	cout << "*ptr = " << *ptr << endl;
	delete ptr;

	// � ������ �������:
	int n; cin >> n;
	ptr = new int[n] {1, 2, 3, 4, 5, 6};
	for (int i = 0; i < n; i++)
		cout << ptr[i] /* ��������� ����� */ << ' ';// << *(ptr + i) /* �������� ����� */;

	delete[] ptr;

	return 0;
}