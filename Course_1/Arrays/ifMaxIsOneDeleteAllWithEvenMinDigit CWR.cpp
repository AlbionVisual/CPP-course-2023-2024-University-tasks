#include <iostream>
#include <ctime>
using namespace std;

void fillArr(int[], int, int= -RAND_MAX / 2, int= RAND_MAX / 2);
void outputArr(int[], int);

bool isMaxOne(int[], int);
int minDigit(int);
int rebuildArr(int[], int);
void deleteElem(int[], int, int);

int main() {

	// cout << (-1) % 10; ����� ������ :)

	const int SIZE = 10;
	int arr[SIZE];

	fillArr(arr, SIZE); // ����
	cout << "Array before: ";
	outputArr(arr, SIZE);

	int newSize; // ����� �������������� ������ ������� ����������
	if (isMaxOne(arr, SIZE)) { // ���� ������������ ������������
		newSize = rebuildArr(arr, SIZE); // ������������� ������
		cout << endl << "Arr after: "; outputArr(arr, newSize); cout << endl;
	}
	else cout << "Max number isn't alone!"; // ����� ������� ��� ����� �� ���

	return 0;
}

// ���� / ����� �������
void fillArr(int arr[], int n, int min, int max) {
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		arr[i] = rand()%(max-min)+min;
	}

}
void outputArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}

bool isMaxOne(int arr[], int n) { // �������� ������������ �� ������������ ��������
	int max = arr[0];
	bool isAlone = true;
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			isAlone = true;
			max = arr[i];
		}else if (arr[i] == max) {
			isAlone = false;
		}
	}
	return isAlone;
}
int minDigit(int num){ // ����� ����������� �����
	int min = num % 10;
	num /= 10;
	while (num) {
		if (num % 10 < min) min = num % 10;
		num /= 10;
	}
	return min;
}
int rebuildArr(int arr[], int n) { // �������������� �������
	for (int i = 0; i < n; i++) {
		if (minDigit(abs(arr[i])) % 2 == 0) { // abs ����� ��-�� ������� ������
			deleteElem(arr, n, i); // ���� ����������� ����� ������, �� ������� ���� �������
			n--; // ��������� ������ �� 1
			i--; // � ������� ������ ��� ��������, �. �. ��� ����� ���������� �� 1
		}
	}
	return n;
}
void deleteElem(int arr[], int size, int ind) { // �������� ��������
	for (int i = ind; i < size-1; i++) {
		arr[i] = arr[i + 1]; // �������� ���� ��������� �� 1 ������� � i-���
	}
	arr[size - 1] = 0; // ��������� ������� ����������
}