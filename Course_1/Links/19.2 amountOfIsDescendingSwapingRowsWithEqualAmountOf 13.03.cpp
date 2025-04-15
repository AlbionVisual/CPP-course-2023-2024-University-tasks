#include <iostream>

// !!! Первый элемент каждой строки есть его длина !!! //

using namespace std;

bool isDescending(int);							// Проверяет все ли цифры расположены в порядке убывания
int amountOfDescending(int*);					// Считает кол-во групп

int** makeMatr(int&);							// Функции для работы с матрицами
void deleteMatr(int**, int);
void initMatr(int**, int);
void output(int**, int);

void findAndReplace(int**, int);				// Находит и изменяет матрицу по условию
void swap(int**, int, int);						// Меняет местами строки матрицы, элементы массива соответственно
void swap(int*, int, int);



int main() {

	// 2.	Составить функцию для нахождения в одномерном массиве количества 
	//		элементов, цифры которых расположены в порядке убывания(например, 
	//		54321).
	//		В двумерном массиве размера(n, m) строки - соседи(строки с
	//		индексами 0 и 1, 2 и 3, 4 и 5), содержащие одинаковое количество
	//		элементов, цифры которых расположены в порядке убывания, поменять
	//		местами и в каждой строке удалить первый такой элемент.

	/**/

	int n;
	int** matr = 0;								// Инициализация переменных

	bool isMemory = 0;
	int choice = -1;
	while (choice != 6) {						// Меню
		// create 1, init 2, print 3, delete 4, callFunc 7, clear 5, end 6
		cout << "Create --> 1\t\tinit --> 2\nprint --> 3\t\tdelete --> 4\nclear --> 5\t\tend --> 6\n\tcall func --> 7\nEnter number: "; cin >> choice;

		switch (choice) {
		case 1:
			if (!isMemory) matr = makeMatr(n);
			else cout << "You already have matrix! (you can delete and than create new)\n";
			isMemory = true;
			break;
		case 2:
			if (isMemory) initMatr(matr, n);
			else cout << "You don't have memory for this, make matrix first!\n";
			break;
		case 3:
			if (isMemory) output(matr, n);
			else cout << "You don't have matrix, make it first!\n";
			break;
		case 4:
			if (isMemory) deleteMatr(matr, n);
			else cout << "You don't have matrix, nothing to delete!\n";
			isMemory = false;
			break;
		case 5: system("cls"); continue;
		case 6:
			if (isMemory) {
				cout << "You didn't free the memory, delete matrix first!\n";
				choice = 0;
			}
			break;
		case 7:
			if (isMemory) findAndReplace(matr, n);
			else cout << "You don't have matrix, make it first!\n";
			break;
		default: cout << "\nTry again:"; break;
		}

		cout << endl;
	}


	return 0;
}

bool isDescending(int num) {

	short digit = num % 10; num /= 10;
	while (num > 0) {
		if (digit >= num % 10) return false;
		num /= 10;
	}

	return true;
}
int amountOfDescending(int* arr) {
	int counter = 0;

	for (int* p = arr + 1; p < arr + arr[0] + 1; p++)
		if (isDescending(*p)) counter += 1;

	return counter;
}

int** makeMatr(int& n) {
	int m;
	cout << "Enter size (x, y): "; cin >> m >> n;
	int** matr = new int* [n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[m + 1];
		matr[i][0] = m;
	}
		

	return matr;
}
void deleteMatr(int** matr, int n) {
	for (int i = 0; i < n; i++)
		delete[] matr[i];

	delete[] matr;
}
void initMatr(int** matr, int n) {
	cout << "Enter matrix:\n";
	for (int i = 0; i < n; i++)
		for (int j = 1; j < matr[i][0] + 1; j++)
			cin >> matr[i][j];
}
void output(int** matr, int n) {
	for (int i = 0; i < n; i++) {
		for (int* q = matr[i] + 1; q <= matr[i] + matr[i][0]; q++)
			cout << *q << ' ';
		cout << endl;
	}
}

void swap(int** matr, int i, int j) {
	int* temp = matr[i];
	matr[i] = matr[j];
	matr[j] = temp;
}
void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void findAndReplace(int** matr, int n) {
	for (int i = 0; i < n; i += 2) {
		if (amountOfDescending(matr[i]) == amountOfDescending(matr[i + 1])) {
			swap(matr, i, i + 1);
			int id = 1;

			while (!isDescending(matr[i][id])) id += 1;
			for (int j = id; j < matr[i][0] + 1; j++) {
				matr[i][j] = matr[i][j + 1];
			}
			matr[i][0] -= 1;

			while (!isDescending(matr[i + 1][id])) id += 1;
			for (int j = id; j < matr[i + 1][0] + 1; j++) {
				matr[i + 1][j] = matr[i + 1][j + 1];
			}
			matr[i + 1][0] -= 1;
		}
	}
}