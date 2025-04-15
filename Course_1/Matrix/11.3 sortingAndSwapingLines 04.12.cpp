#include <iostream>
using namespace std;

const int SIZE = 30;		// Максимальный размер матрицы / массива

void output(int[][SIZE], int);
void swapLines(int[][SIZE], int, int, int);
void sort(int[][SIZE], int, int);
int maxDigit(int);

int main() {

	// 3. Ввести/вывести массив matr(n, n). Отсортировать массив в порядке
	//    возрастания максимальных цифр элементов первого столбца массива,
	//    используя эффективную сортировку методом "пузырька"

	int n; cout << "Enter size (n < 30): "; cin >> n;

	int matr[SIZE][SIZE];
	cout << "Enter Matrix (" << n << "x" << n << "):\n";
	for (int i = 0; i < n; i++) {							// Ввод матрицы
		for (int j = 0; j < n; j++) {
			cin >> matr[i][j];
		}
	}

	int colNum; cout << "Enter col to sort (1 - " << n << "): "; cin >> colNum; colNum--; // Ввод номера столбца по которому сортировать матрицу

	cout << "Your matrix:\n";								// Вывод
	output(matr, n);
	cout << endl << endl;

	sort(matr, n, colNum);								    // Сортировка матрицы :(

	cout << "Sorted matrix:\n";								// Вывод
	output(matr, n);
	cout << endl << endl;

	return 0;
}

void output(int matr[][SIZE], int n = SIZE) {
	for (int i = 0; i < n; i++) {				// вывод массива
		for (int j = 0; j < n; j++) {
			cout.width(6);		cout << matr[i][j];
		}
		cout << endl;
	}
}
void sort(int matr[][SIZE], int n = SIZE, int col = 0) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i-1; j++)
			if (maxDigit(matr[j][col]) > maxDigit(matr[j + 1][col]))
				swapLines(matr, n, j, j + 1);
}
int maxDigit(int num) {
	int max = -1;
	while (num) {
		if (max < num % 10) {
			max = num % 10;
		}
		num /= 10;
	}
	return max;
}
void swapLines(int matr[][SIZE], int n, int ind1, int ind2) {
	for (int i = 0; i < n; i++) {
		int temp = matr[ind1][i];
		matr[ind1][i] = matr[ind2][i];
		matr[ind2][i] = temp;
	}
}