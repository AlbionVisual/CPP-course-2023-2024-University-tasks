#include <iostream>
using namespace std;

int main() {

	// Initialising and creating
	char simv = 'A';		// ���������� ���������� simv �� ��������� 'A'

	// Input and output
	char simv;		cin >> simv;
	cout << "simv = " << simv << endl;

	char a, b;
	cin >> a >> b;					// ����� 53
	cout << a << ' ' << b << ' '				// a = 5, b = 3
		<< a % b << ' ' << a / b << '\n';		// a(53) % b(51) = 2, a / b = 1

	char simv;
	cout << "Enter simvol: ";	simv = cin.get();			// �����   A
	cout << " simv = " << simv << endl;				// simv = A

	cout << "Enter simvol: ";	char simv = getchar();		// �����   D
	cout << " simv = " << simv << endl;				// simv = D

	cin.ignore();			// "������" ����� ��� getline()

	char simv = 'f';
	cout.put(simv);						// f
	cout << "\nsimv =  " << simv << endl;			// simv = f;

	// Usage
	int k = 1;
	for (simv = 'A'; simv <= 'Z'; simv++) {
		for (int j = 1; j <= k; j++)
			cout << simv;
		cout << endl;
		k++;
	}
	cout << endl;


	// ---- Arrays (strings) ----
	// Creating and initializing
	char str[20];	// ������������ ����� �������� �����  ���� 19

	char str[6] = "HELLO";	// ������������� ����������� 
					// � ����� ������� ������ '\0'.
	char str[] = "HELLO";		// ������ ������� ����� �� ���������
	char str[] = { 'H', 'E', 'L', 'L', 'O', '\0' };
	char str[] = { 'h', 'e', 'l', 'l', 'o', '\0' };

	char str[10];	//str = "Hello";		// ������!!!
	char str1[10], str2[10] = "ffff";
	//str1 = str2;						// ������!!!


	// Input output arrays
	char str[10];
	cout << "Enter row: ";		cin >> str;		// ����� ABCDEF
	cout << "str = " << str << endl;				// ABCDEF

	char str[20];
	cin >> str;					// �����, ��������, 111 2222
	cout << "str = " << str << endl;		// 111

	// gets_s(���_�������);
	const int MAX = 20;
	cin.get(str, MAX);
	cin.getline(str, MAX);




	return 0;
}