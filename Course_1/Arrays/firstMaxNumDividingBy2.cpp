#include <iostream>

using namespace std;

bool isEven(int);

int main() {

	// Ввести/вывести одномерный массив mas(n). Найти в массиве первый
	// максимальный элемент и его индекс среди чётных элементов массива.
	// Если чётных элементов нет, выдать сообщение

	const int SIZE = 4;
	int arr[SIZE];
	int max, ind = -1;

	// Ввод массива
	cout << "Enter your array: "; for (int i = 0; i < SIZE; i++) cin >> arr[i];

	for (int i = 0; i < SIZE; i++) { // Перебор массива
		
		if (isEven(arr[i])) { // В случае если элемент чётное число и больше чем max

			if (ind == -1) { // Если чётный элемент встречается впервые
				max = arr[i];
				ind = i;
				continue;
			}

			if (arr[i] > max) { // Если нашёлся элемент больше
				max = arr[i];
				ind = i;
			}
		}
	}

	// Вывод результата
	if (ind != -1) {
		cout << "Your element: " << arr[ind] << " and it's index: " << ind;
	}
	else cout << "There is no even numbers";


	return 0;
}

// Проверка числа на чётность
bool isEven(int num) {
	if (num % 2 == 0)return true;
	else return false;
}