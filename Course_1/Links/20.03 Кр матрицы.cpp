#include <iostream>

using namespace std;

int** initMatr(int, int);						// Инициализация матрицы
void output(int**, int, int);					// Вывод матрицы
void deleteMatr(int**, int);					// Удаление матрицы
bool isPrime(int);								// Проверяет простое ли число
void sortByPrime(int**, int, int);				// Сортировка по кол-ву простых чисел в строке
void addZeros(int**, int&, int);				// Добавление нулей

int main() {

	/*
	
		1 1 13 1 1 13
		6 6 6 17 17 6
		19 19 19 8 19 8
		4 11 4 14 4 14
		53 12 53 12 12 53

			-- или --

		1 2 3 4 5 6 7 8 9
		10 11 12 13 14 15 16 17 18
		13 13 13 13 13 17 4 4 4
		1 1 1 17 19 21 23 35 37

	*/

	int n, m; cout << "Enter matrix size (x, y): "; cin >> m >> n;

	cout << "Enter matr:\n";					
	int** matr = initMatr(n, m);				// Ввод матрицы


	sortByPrime(matr, n, m);
	cout << "\nSorted matrix:\n";				// Сортировка матрицы
	output(matr, n, m);


	addZeros(matr, n, m);
	cout << "\nEdited matr:\n";					// Добавление нулевых строк в матрицу
	output(matr, n, m);


	deleteMatr(matr, n);						// Очищение памяти
}

int** initMatr(int n, int m) {
	int** matr = new int* [2 * n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> matr[i][j];
		}
	}
	return matr;
}
void output(int** matr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matr[i][j] << ' ';
		}
		cout << endl;
	}
}
void deleteMatr(int** matr, int n) {
	for (int i = 0; i < n; i++) {
		delete[] matr[i];
	}
	delete[] matr;
}
bool isPrime(int num) {
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0) return false;
	if (num != 1) return true;
	else return false;
}
void sortByPrime(int** matr, int n, int m) {
	int* amounts = new int[n];
	for (int i = 0; i < n; i++) {
		amounts[i] = 0;
		for (int j = 0; j < m; j++) {
			if (isPrime(matr[i][j])) amounts[i]++;
		}
	}

	for (int i = 0; i < n; i++) {
		bool noSwap = true;
		for (int j = 0; j < n - i - 1; j++) {
			if (amounts[j] > amounts[j + 1]) {

				noSwap = false;

				int tmp = amounts[j];
				amounts[j] = amounts[j + 1];
				amounts[j + 1] = tmp;

				int* buff = matr[j];
				matr[j] = matr[j + 1];
				matr[j + 1] = buff;
			}
		}
		if (noSwap) break;
	}
}
void addZeros(int** matr, int& n, int m) {
	int* amounts = new int[2 * n];
	for (int i = 0; i < n; i++) {
		amounts[i] = 0;
		for (int j = 0; j < m; j++)
			if (isPrime(matr[i][j])) amounts[i]++;
	}

	for (int i = 0; i < n; i++) {
		if (amounts[i] % 2 == 0) {

			for (int j = n; j > i + 1; j--) {
				matr[j] = matr[j - 1];
				amounts[j] = amounts[j - 1];
			}

			i++;
			n++;
			matr[i] = new int[m];
			amounts[i] = 1;
			for (int j = 0; j < m; j++)
				matr[i][j] = 0;
		}
	}
}