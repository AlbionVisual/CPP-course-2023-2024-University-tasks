#include <iostream>

using namespace std;

int countHexDigits(int);								// Считает кол-во 16-ых цифр числа

int main() {

	// 2.	Составить функцию, которая для одного целого числа определяет, 
	//		сколько в его записи 16 - ых цифр - букв(т.е.цифры A - F).Для 
	//		выделения цифр использовать битовые операции.
	//		Ввести / вывести массив целых чисел mas(n).Найти среди элементов 
	//		массива, которые содержат 16 - ые цифры - буквы первый 
	//		элемент(его индекс и сам элемент) содержащий максимальное
	//		количество 16 - ых цифр - букв, и удалить его.Предусмотреть 
	//		случай, если в массиве нет элементов, которые содержат 16 - ые
	//		цифры - буквы.Дополнительный массив не использовать.

	int n; const int N = 100; int mass[N];
	cout << "Enter array size: "; cin >> n;
	
	cout << "Enter your array:\n";						// Ввод
	for (int i = 0; i < n; i++) {
		cin >> hex >> mass[i];
	}

	int maxAmount = 0;
	int id = -1;
	for (int i = 0; i < n; i++) {						// Ищем маскимальный
		if (countHexDigits(mass[i]) > maxAmount) {
			maxAmount = countHexDigits(mass[i]);
			id = i;
		}
	}



	if (id != -1) {										// Если есть элементы
		for (int* i = &mass[id]; i != &mass[n-1]; i++) 				// Удаляем 1ый максимальный
			*i = *(i + 1);

		n--;

		for (int i = 0; i < n; i++) {
			cout << hex << mass[i] << ' ';
		}
	}
	else {
		cout << "Your array doesn't have any numbers with hex digits.";
	}

	

	return 0;
}

int countHexDigits(int num) {
	
	int counter = 0, eraser = 15;

	while (num != 0) {

		if ((num & eraser) >= 10)
			counter++;

		num = num >> 4;
	}

	return counter;
}