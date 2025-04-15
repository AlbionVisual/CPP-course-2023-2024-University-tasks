#include <iostream>

using namespace std;

int countingPairs(int* arr, int n);					// Вычисляет кол-во пар

int main() {

	// 3.	Составить функцию, которая для одномерного массива целых чисел
	//		определяет количество пар соседних элементов, у которых старшие 
	//		цифры одинаковые.
	//		В массиве mas(n, m) (m—чётное), используя функцию, в каждой строке
	//		определить количество пар соседних элементов, у которых старшие
	//		цифры одинаковые, и удалить строки, содержащие чётное количество
	//		таких пар.Для перестановки строк использовать массив указателей на
	//		строки.Дополнительный массив не использовать.

	//		4 4
	//		123 234 245 345
	//		3453 3 356 456
	//		1453 1 1534 145
	//		2 4 536 7347

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

	for (int i = 0; i < n; i++) {
		if (countingPairs(ptr[i], m) % 2 == 0) {
			n--;
			for (int j = i; j < n; j++) {
				ptr[j] = ptr[j + 1];
			}										// Преобразования
			i--;
		}
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

int firstDigit(int n) {								// Ищет первую цифру числа
	while (n > 9) n /= 10;
	return n;
}

int countingPairs(int* arr, int n) {
	short counter = 0;
	for (int* p = arr; p < &arr[n]; p++) {
		if (firstDigit(*p) == firstDigit(*(p + 1))) {
			counter++;
			p++;
		}
	}
	return counter;
}