// Нарушена структура, отсутствуют комментарии, зато быстро и дёшево по памяти
// не давать на проверку
#include <iostream>

using namespace std;

int* selectNum(int*, int*); 
int countEvenDigs(int);

int main() {

	// 1.	Составить функцию, которая для двух натуральных чисел, 
	//		переданных в функцию по указателю, определяет число, у которого
	//		сумма чётных цифр больше, и возвращает его адрес в main(). Ввести 
	//		вывести одномерный массив натуральных чисел mas(n).Для каждой пары,
	//		рядом стоящих элементов в массиве, определить элемент, у которого
	//		сумма чётных цифр больше.Создать массив таких элементов и вывести 
	//		его на экран.


	const int N = 100;
	int n; int mass[N];

	cout << "Enter array size: "; cin >> n;
	cout << "Enter your array:\n";

	for (int i = 0; i < n; i++) {
		cin >> mass[i];

		if (i % 2 == 1) {
			mass[i - 1] = *selectNum(mass + i - 1, mass + i);
		}
	}

	cout << "Your new array: ";
	for (int i = 0; i < n / 2; i++) {
		cout << mass[i * 2] << ' ';
	}

	return 0;
}

int* selectNum(int* a, int* b) {

	if (countEvenDigs(*a) > countEvenDigs(*b))
		return a;
	else
		return b;

}

int countEvenDigs(int n) {
	
	int sum = 0;

	while (n != 0) {
		if ((n % 10) % 2 == 0) {
			sum += n % 10;
		}
		n /= 10;
	}
	cout << endl << sum << endl;

	return sum;
}