#include <iostream>

using namespace std;

int countAvg(int* arr, int n);							// Среднее арифметическое положительных чисел

int main() {

	// 1.	Составить функцию, которая для одномерного массива 
	// 		целых чисел находит среднее арифметическое положительных
	// 		элементов. В случае, если в массиве нет положительных элементов, функция возвращает 0.
	// 		В массиве mas(n, m), используя составленную функцию, найти номер строки (первой),
	// 		среднее арифметическое положительных элементов которой является наибольшим, и поменять
	// 		её местами с первой строкой (с индексом 0). Для перестановки строк использовать массив
	// 		указателей на строки. Дополнительный массив не использовать.

	const short int BORDER = 25;
	int n, m; cout << "Enter size (x, y): "; cin >> m >> n;

	int arr[BORDER][BORDER];
	cout << "Enter matrix:\n";
	for (int i = 0; i < n; i++) {								// Ввод
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int maxAvg = countAvg(arr[0], m), ind = 0;
	for (int i = 1; i < n; i++) {
		if (countAvg(arr[i], m) > maxAvg) {
			ind = i; maxAvg = countAvg(arr[i], m);			// Ищем максимальное среднее
		}
	}

	int* ptrArr[BORDER];
	for (int i = 0; i < n; i++) {
		ptrArr[i] = arr[i];
	}

	int* p = ptrArr[0];
	ptrArr[0] = ptrArr[ind];									// Меняем местами
	ptrArr[ind] = p;

	cout << "\nYour matrix:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ptrArr[i][j] << ' ';						// Вывод
		}
		cout << endl;
	}
	return 0;
}

int countAvg(int* arr, int n) {
	int sum = 0, count = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			sum += arr[i];
			count += 1;
		}
	}

	return count != 0 ? sum / count : 0;
}