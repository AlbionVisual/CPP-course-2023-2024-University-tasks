#include <iostream>

using namespace std;

int countPals(int* arr, int n);						// Считает сколько палиндромов в массиве

int main() {

	// 2.	Составить функцию, которая для одномерного массива натуральных
	//		чисел определяет, сколько в нём элементов-палиндромов.
	//		В массиве matr(n, m) после строки(первой), содержащей наименьшее 
	//		количество элементов - палиндромов, вставить нулевую строку(все 
	//		элементы равны 0).Для перестановки строк использовать массив 
	//		указателей на строки.Дополнительный массив не использовать.

	//		5 5
	//		131    34    3223    52   4114
	//		2332  451  15451  672  617
	//		411    2992  521    72    288
	//		42      1331  155    413  513
	//		811    5445  166   118   32123	

	const short MAX = 20;

	int n, m; cout << "Enter size (x, y): "; cin >> m >> n;

	int arr[MAX][MAX];
	cout << "Enter array:\n";						// Ввод
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int* ptr[MAX];
	for (int i = 0; i < n; i++) ptr[i] = arr[i];

	short min = countPals(ptr[0], m), id = 0;
	for (int i = 1; i < n; i++) {
		if (countPals(ptr[i], m) < min) {
			id = i; min = countPals(ptr[i], m);		// Поиск нужной строки
		}
	}
	id++;
	for (int i = n++; i > id; i--) {
		ptr[i] = ptr[i - 1];						// Преобразование
	}
	ptr[id] = arr[n];
	for (int i = 0; i < m; i++) {
		ptr[id][i] = 0;
	}

	cout << "\nYour array:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ptr[i][j] << ' ';
		}											// Вывод
		cout << endl;
	}

	return 0;
}

bool isPalindrom(int num) {							// Проверяет палиндром ли число
	int temp = num, rev = 0;
	while (temp) {
		rev = rev * 10 + temp % 10;
		temp /= 10;
	}
	return rev == num;
}
int countPals(int* arr, int n) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (isPalindrom(arr[i])) {
			counter++;
		}
	}
	return counter;
}