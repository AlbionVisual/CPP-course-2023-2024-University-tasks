#include <iostream>

using namespace std;

bool containsHex(int);						// Верно в случае наличия 16-ых цифр в числе
int maxDigit(int);							// Максимальная цифра числа
int oldestDigit(int);						// Старшая цифра числа

int main() {

	// 3.	Составить функцию, которая для одного целого числа определяет,
	//		есть  в его записи 16-ые цифры-буквы (т.е. цифры A-F) или нет. 
	//		Для выделения цифр использовать битовые операции.
	//		Ввести / вывести массив целых чисел mas(n).Найти в массиве 
	//		максимальный элемент(первый) среди элементов, которые не 
	//		содержат ни одной 16 - ой буквы - цифры(A–F), вставить перед ним
	//		заданное число(вводится), и определить-- - совпадают в нём(в 
	//		максимальном элементе) значения максимальной цифры и старшей или 
	//		нет.Выдать сообщение.Предусмотреть случай, если в массиве нет 
	//		элементов, не содержащих 16 - ых букв - цифр.
	


	int n; cout << "Enter array size: "; cin >> n;
	const int N = 100; int mass[N];

	cout << "Enter array:\n";
	for (int i = 0; i < n; i++)				// Ввод
		cin >> hex >> mass[i];

	int addence;
	cout << "Enter number to concatanate: "; cin >> hex >> addence;

	cout << endl;


	int id = -1, max_val;
	for (int i = 0; i < n; i++) {
		if (!containsHex(mass[i])) {
			if (id == -1) {
				id = i; max_val = mass[i];	// Поиск максимального
			}
			else if (mass[i] > max_val) {
				id = i; max_val = mass[i];
			}
		}
	}

	if (id != -1) {

		for (int* i = &mass[n]; i >= &mass[id]; i--)		// Вставка элемента
			*i = *(i - 1);

		mass[id] = addence; n++; id++;

		cout << "Your array: ";
		for (int i = 0; i < n; i++) {
			cout << hex << mass[i] << ' ';					// Вывод
		}

		if (maxDigit(mass[id]) == oldestDigit(mass[id])) cout << "\nMax element: " << mass[id] << " - Match.";
		else cout << "\nMax element: " << mass[id] << " - Don't match.";

	}
	else {
		cout << "No numbers with hex digits.";
	}

	cout << "\n\n";

	return 0;
}



bool containsHex(int num) {

	int eraser = 15;

	while (num != 0) {

		if ((num & eraser) >= 10)
			return 1;

		num = num >> 4;
	}

	return 0;
}


int maxDigit(int num) {
	int max = 0;

	while (num > 0) {

		if (num % 16 > max)
			max = num % 16;
	
		num /= 16;
	}
	return max;
}

int oldestDigit(int num) {

	while (num / 16 > 0) {
		num /= 16;
	}

	return num;
}