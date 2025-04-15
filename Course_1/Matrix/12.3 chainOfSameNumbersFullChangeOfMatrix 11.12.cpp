#include <iostream>
using namespace std;

int longestChain(int[], int);						// Прототип longestChain

int main() {

	// 3. В массиве удалить все строки, у которых нет цепочек равных элементов,
	//    стоящих подряд, подтянув остальные строки. Оставшиеся строки
	//	  расположить по возрастанию максимальных длин цепочек равных
	//    элементов, стоящих подряд, в строках.

	const int X = 30, Y = 30;

	int n, m; cout << "\nEnter size of your matrix (n, m): "; cin >> n >> m; cout << endl;
	int matr[Y][X];
	cout << "Enter your matrix:\n";
	for (int i = 0; i < n; i++)						// Ввод матрицы
		for (int j = 0; j < m; j++)
			cin >> matr[i][j];

	cout << "\nYour matrix:\n";
	for (int i = 0; i < n; i++) {					// Вывод матрицы
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << ' ';
		cout << endl;
	}

	for (int i = 0; i < n; i++) {					// Удаляем все строки без цепочек равных чисел
		if(longestChain(matr[i], m) == 1) {
			for (int j = i; j < n; j++) {
				for (int k = 0; k < m; k++) {
					matr[j][k] = matr[j + 1][k];
				}
			}
			n--;
			i--;
		}
	}

	for (int i = n-1; i >0; i--) {					// Сортируем строки матрицы
		for (int j = 0; j < i; j++) {
			if (longestChain(matr[j], m) > longestChain(matr[j + 1], m)) {
				for (int k = 0; k < m; k++) {
					int buff = matr[j][k];
					matr[j][k] = matr[j + 1][k];
					matr[j + 1][k] = buff;
				}
			}
		}
	}

	cout << "\nNew matrix:\n";
	for (int i = 0; i < n; i++) {					// Вывод новой матрицы
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << ' ';
		cout << endl;
	}

	return 0;
}

int longestChain(int arr[], int size) {				// Функция longestChain
	int counter = 1, max = 1, prev = arr[0];
	for (int i = 1; i < size; i++) {
		if (prev == arr[i]) {
			counter++;
		} else {
			if (max < counter) max = counter;
			counter = 1;
		}
		prev = arr[i];
	}
	if (max < counter) max = counter;
	return max;
}