#include <iostream>

using namespace std;

int** makeMatr(int&, int&);							// Функции для работы с матрицами
void deleteMatr(int**, int);
void initMatr(int**, int, int);
void output(int**, int, int);

void addZeros(int**, int&, int);					// Добавление нулей после каждой строки количество максимальных элементов которой чётное
int amountOfMaxies(int*, int);						// Вспомогательная ф-ция (считает кол-во максимальных элементов)

int main() {

	// 3.	В двумерном массиве matr(n, m) после каждой строки, количество
	//		максимальных элементов (поиск за один просмотр) у которых чётное,
	//		вставить нулевую строку (все элементы равны нулю). Дополнительный
	//		массив не использовать. 

	/*
		
		1 2 3 4 5
		1 1 34 5 5
		1 5 7435 7435 17
		146 146 146 146 146
		335 335 1 335 335

	*/

	int n, m;
	int** matr = 0;									// Инициализация переменных

	bool isMemory = false;
	int choice = -1;
	while (choice != 6) {						// Меню
		// create 1, init 2, print 3, delete 4, callFunc 7, clear 5, end 6
		cout << "Create --> 1\t\tinit --> 2\nprint --> 3\t\tdelete --> 4\nclear --> 5\t\tend --> 6\n\tadd 0 after even maxies --> 7\nEnter number: "; cin >> choice;

		switch (choice) {
		case 1: 
			if (!isMemory) matr = makeMatr(n, m);
			else cout << "You already have matrix! (you can delete and than create new)\n";
			isMemory = true;
			break;
		case 2: 
			if (isMemory) initMatr(matr, n, m); 
			else cout << "You don't have memory for this, make matrix first!\n";
			break;
		case 3: 
			if (isMemory) output(matr, n, m);
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
			if (isMemory)addZeros(matr, n, m);
			else cout << "You don't have matrix, make it first!\n";
			break;
		default: cout << "\nTry again:"; break;
		}

		cout << endl;
	}

	return 0;
}

int** makeMatr(int& n, int& m) {
	cout << "Enter size (x, y): "; cin >> m >> n;
	int** matr = new int* [2 * n];
	for (int i = 0; i < n; i++)
		matr[i] = new int[m];

	return matr;
}
void deleteMatr(int** matr, int n) {
	for (int i = 0; i < n; i++)
		delete[] matr[i];

	delete[] matr;
}
void initMatr(int** matr, int n, int m) {
	cout << "Enter matrix:\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matr[i][j];
}
void output(int** matr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int* q = matr[i]; q < &matr[i][m]; q++)
			cout << *q << ' ';
		cout << endl;

	}
}

int amountOfMaxies(int* arr, int n) {
	int max = arr[0];
	int amount = 1;
	for (int* p = &arr[1]; p < &arr[n]; p++) {
		if (*p > max) {
			amount = 1;
			max = *p;
		}
		else if (*p == max) amount += 1;
	}
	return amount;
}
void addZeros(int** matr, int& n, int m) {
	for (int i = 0; i < n; i++) {
		if (amountOfMaxies(matr[i], m) % 2 == 0) {
			for (int j = n; j > i + 1; j--) {
				matr[j] = matr[j - 1];
			}

			matr[i + 1] = new int[m];
			for (int j = 0; j < m; j++)
				matr[i + 1][j] = 0;
			n++; i++;
		}
	}
}