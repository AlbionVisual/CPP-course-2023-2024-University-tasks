#include <iostream>
using namespace std;

const int SIZE = 30;					// ������������ ������ ������� \ �������

int letterAmount(int);
void outputHex(int[][SIZE], int);
int amountOfElems(int[], int);
void swapLines(int[][SIZE], int, int, int);

int main() {

	// 2. ������/������� ������ matr(n, n). �������� ������� ������ ������,
	//    ������� � ������������ ����������� ���������, ���������� ������ ���
	//    16-� �����-�����, �� ������� � ����������� ����������� ���������,
	//    ����������  ������ ��� 16-� �����-�����.

	int n; cout << "Enter size: "; cin >> n;					// ���� �������

	int matr[SIZE][SIZE];
	cout << "Enter Matrix (" << n << "x" << n << "):\n";
	for (int i = 0; i < n; i++) {								// ���� �������
		for (int j = 0; j < n; j++) {
			cin >> hex >> matr[i][j];
		}
	}

	cout << "Your matr: " << endl;
	outputHex(matr, n);
	cout << endl << endl;

	int max = 0, idMax = -1, min = n + 1, idMin = -1;			// ��������
	for (int i = 0; i < n; i++) {
		if (amountOfElems(matr[i], n) > max) {
			max = amountOfElems(matr[i],n);
			idMax = i;
		}
		if (amountOfElems(matr[i], n) < min && amountOfElems(matr[i], n) != 0) {
			min = amountOfElems(matr[i], n);
			idMin = i;
		}
	}

	if (idMin == -1 || idMax == -1) {							// �����
		cout << "There's no lines that fits the condition";
	} else {
		swapLines(matr, n, idMax, idMin);
		cout << "Matrix after swaping:\n";
		outputHex(matr, n);
	}




	return 0;
}

int letterAmount(int num) { // ���-�� ��������� � �����
	int counter = 0;
	while (num) {
		if (num % 16 >= 10) {
			counter++;
		}
		num /= 16;
	}
	return counter;
}
void outputHex(int matr[][SIZE], int n = SIZE) {
	for (int i = 0; i < n; i++) {				// ����� �������
		for (int j = 0; j < n; j++) {
			cout.width(6);		cout << hex << matr[i][j];
		}
		cout << endl;
	}

}
int amountOfElems(int arr[], int n = SIZE){
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (letterAmount(arr[i])==2) {
			counter++;
		}
	}
	return counter;
}
void swapLines(int matr[][SIZE], int n, int ind1, int ind2) {
	for (int i = 0; i < n; i++) {
		int temp = matr[ind1][i];
		matr[ind1][i] = matr[ind2][i];
		matr[ind2][i] = temp;
	}
}