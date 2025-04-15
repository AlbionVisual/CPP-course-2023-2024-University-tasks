#include <iostream>

using namespace std;

bool isDescending(int);							// Проверяет все ли цифры расположены в порядке убывания
int countGroups(int*, int);						// Считает кол-во групп

int** makeMatr(int&, int&);						// Функции для работы с матрицами
void deleteMatr(int**, int);
void initMatr(int**, int, int);
void output(int**, int, int);

void findAndDelete(int**, int&, int);			// Ищет и удаляет строки подходящие по условию
void sortRows(int**, int, int);					// Сортирует строки по условию
void swap(int**, int, int);						// Меняет местами элементы матрицы, массива соответственно
void swap(int*, int, int);



int main() {

	// 4.	Составить функцию для нахождения в одномерном массиве количества
	//		групп стоящих подряд элементов, цифры которых расположены в порядке
	//		убывания.
	//		В двумерном массиве размера(n, m) удалить строки(не создавать
	//		дополнительный массив), не содержащие таких групп элементов.
	//		Оставшиеся строки расположить в порядке возрастания количества
	//		таких групп, используя эффективную сортировку методом "пузырька"
	//		(т.е.без лишних просмотров элементов массива).Можно создать
	//		дополнительный одномерный массив количеств таких групп в строках.
	//		Использовать составленную функцию для строк заданного двумерного
	//		массива.Указатели на строки.
	
	/*
	
		654 765 876 987
		1 34 54 56
		34 654 765 345
		264 733 752 7654
		45 56 67 78

		321 234 345 456 765 678 789 321
		321 432 456 654 876 345 541 543
		345 567 876 12 13 543 123 432
		12 13 14 15 654 764 18 345
		456 531 876 34 321 986 23 234

	*/

	int n, m;
	int** matr = 0;									// Инициализация переменных

	int choice = -1;
	while (choice != 6) {						// Меню
		// create 1, init 2, print 3, delete 4, callFunc 7, clear 5, end 6
		cout << "Create --> 1\t\tinit --> 2\nprint --> 3\t\tdelete --> 4\nclear --> 5\t\tend --> 6\n\tremove 0ed rows --> 7\n\tsort rest rows --> 8\nEnter number: "; cin >> choice;

		switch (choice) {
		case 1: matr = makeMatr(n, m); break;
		case 2: initMatr(matr, n, m); break;
		case 3: output(matr, n, m); break;
		case 4: deleteMatr(matr, n); break;
		case 5: system("cls"); continue;
		case 6: break;
		case 7: findAndDelete(matr, n, m); break;
		case 8: sortRows(matr, n, m); break;
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
int countGroups(int* arr, int n) {
	int counter = 0;
	for (int* p = arr + 2; p <= &arr[n]; p++)
		if ((p == &arr[n] || !isDescending(*p)) && isDescending(*(p - 1)) && isDescending(*(p - 2)))
			counter++;

	return counter;
}

int** makeMatr(int& n, int& m) {
	cout << "Enter size (x, y): "; cin >> m >> n;
	int** matr = new int* [n];
	for (int i = 0; i < n; i++)
		matr[i] = new int [m];

	return matr;
}
void deleteMatr(int** matr, int n) {
	for (int i = 0; i < n; i++)
		delete [] matr[i];

	delete [] matr;
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
void findAndDelete(int** matr, int& n, int m) {

	for (int i = 0; i < n; i++)
		if (countGroups(matr[i], m) == 0) {
			delete[] matr[i];
			for (int j = i; j < n - 1; j++)
				matr[j] = matr[j + 1];
			n -= 1;
		}
}
void sortRows(int** matr, int n, int m) {

	int* amounts = new int[n];
	for (int i = 0; i < n; i++)
		amounts[i] = countGroups(matr[i], m);

	for (int i = 0; i < n; i++) {
		bool sorted = false;
		for (int j = 0; j < n - i - 1; j++)
			if (amounts[j] > amounts[j + 1]) {
				swap(matr, j, j + 1); swap(amounts, j, j + 1);
				sorted = true;
			}
		if (!sorted) break;
	}
}