#include <iostream>
#include <cstring>
using namespace std;

int* changeToStars(char**, int, int);					// �������� ����� ����� len �� �����
void sort(char**, int*, int);							// ��������� ������� char �� ����������� ����� �� ������ �������

int main() {

	// 8.	������/������� ������ �����. � ������ ������ �������� �����,
	//		����� ������� ��������� � �������� ������, �� �������� (***   *).
	//		������������� ������ ����� �� ���������� �����, ���������
	//		����������� ���������� ������� "��������" (�.�. ��� ������
	//		���������� ��������� �������). ����� ������� ��������������
	//		���������� ������ ��������� ����� ���� � �������.

	/* 15 4
I'm tellin you
a joke, yeee
here: your
umbrella please
	*/


	int n, m; cout << "Enter sizes of strings (x, y): "; cin >> m >> n;
	char** pstr = new char* [n];
	cin.ignore();											// ����
	cout << "Enter " << n << " rows up to " << m << " characters:\n";
	for (int i = 0; i < n; i++) {
		pstr[i] = new char[m + 1];
		gets_s(pstr[i], m + 1);
	}
	int len; cout << "Enter word size to change with ***: "; cin >> len;

	int* counts = changeToStars(pstr, n, len);				// ���������
	sort(pstr, counts, n);

	cout << "Array rows: \n";
	for (int i = 0; i < n; i++)								// ����� �������
		cout << pstr[i] << endl;


	for (int i = 0; i < n; i++)
		delete[] pstr[i];									// �������� ������
	delete[] pstr;


	return 0;
}

void sort(char** matr, int* amounts, int n) {
	bool isInRow = false;
	for (int i = 0; i < n; i++) {
		isInRow = true;
		for (int j = 0; j < n - i - 1; j++) {
			if (amounts[j] > amounts[j + 1]) {
				isInRow = false;

				int temp = amounts[j];
				amounts[j] = amounts[j + 1];
				amounts[j + 1] = temp;

				char* buf = matr[j];
				matr[j] = matr[j + 1];
				matr[j + 1] = buf;
			}
		}
		if (isInRow) break;
	}
}
int* changeToStars(char** pstr, int n, int len) {
	int* counts = new int[n];
	const char* pat = " .,;:()";

	for (int i = 0; i < n; i++) {
		counts[i] = 0;
		char* rest = pstr[i];
		char* p = &(pstr[i][0]);

		do {
			p = p + strspn(p, pat);
			if (strcspn(p, pat) == len) {
				counts[i]++;
				for (char* q = p; q < p + len && *q; q++) *q = '*';
			}
			p = p + strcspn(p, pat);
		} while (*p);
	}
	return counts;
}