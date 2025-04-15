#include <iostream>

using namespace std;

void inputConsole(int*, int);								// ���� ������� � �������
void outputConsole(int*, int);								// ����� ������� � �������	
void amountAfterRow(int*, int&);								// �������� ������������ ������� ������ ������ ���������

int main() {

	// 2.	������/������� ���������� ������ ����� ����� ������� n. �������������
	//		�������� ������, ������� � ������� ������������ ����� ������ ������
	//		���������� ��������� ��� ���� �������, ������ ����� ��������� ������
	//		�������. �������������� ������ �� ������������

	//		�������� �������:
	// 
	//		5 5 5 2 3 1 1 1 1 6 1 4 4 4 7 8 9
	//		
	//		1 1 1 2 2 2 4 4 4 4


	int choice = -1;
	int n; int* arr = 0;									// �������� ����������

	while (choice != 6) {
		cout << "Create --> 1, Reinit --> 2,\nPrint --> 3, Delete --> 4,\nAdd amount after row --> 5, End --> 6\nSelected: ";
		cin >> choice;
		switch (choice) {									// ����
		case 1:
			cout << "Enter size: "; cin >> n;
			arr = new int[n+1];
		case 2:
			inputConsole(arr, n);
			break;
		case 3:
			outputConsole(arr, n);
			break;
		case 4:
			delete[] arr;
			break;
		case 5:
			amountAfterRow(arr, n);
			break;
		}
		cout << endl;
	}

	return 0;
}

void inputConsole(int* arr, int n) {

	cout << "Enter array: ";

	for (int* p = arr; p < &arr[n]; p++)
		cin >> *p;

}
void outputConsole(int* arr, int n) {

	cout << "Array: ";

	for (int* p = arr; p < &arr[n]; p++)
		cout << *p << ' ';

	cout << endl;

}
void amountAfterRow(int* arr, int& n) {

	int maxSize = 0, start = 0;
	for (int id = 0, i = 0; i < n; i++) {
		id++;
		if (i == n || arr[i] != arr[i + 1]) {
			if (maxSize < id) {
				maxSize = id;
				start = i + 1;
			}
			id = 0;
		}
	}

	for (int* p = &arr[n]; p > &arr[start]; p--)
		*p = *(p-1);

	arr[start] = maxSize;

	n++;

	cout << "Added!";

}