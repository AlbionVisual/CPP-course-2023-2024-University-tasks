#include <iostream>

using namespace std;

void inputConsole(int*, int);								// Ввод массива с консоли
void outputConsole(int*, int);								// Вывод массива в консоль	
bool isPalindrome(int);										// Проверка числа на палиндром
bool containsPalindrome(int*, int);							// Проверка массива на наличие палиндрома
bool isDescending(int*, int);								// Проверка на убывание элементов

int main() {

	// 1.	Ввести/вывести одномерный массив натуральных чисел размера n.
	//		Если массив содержит хотя бы один элемент-палиндром и упорядочен
	//		по убыванию значений элементов, то присвоить переменной pr
	//		значение 1, иначе – значение 0.

	//		Тестовый массив:
	// 
	//		12321 32 31
	//

	int choice = -1;
	int n; int* arr = 0;									// Создание переменных
	int pr;

	while (choice != 6) {
		cout << "Create --> 1, Reinit --> 2,\nPrint --> 3, Delete --> 4,\nCheck condition --> 5, End --> 6\nSelected: ";
		cin >> choice;
		switch (choice) {									// Меню
		case 1:
			cout << "Enter size: "; cin >> n;
			arr = new int[n + 1];
		case 2:
			inputConsole(arr, n);
			break;
		case 3:
			outputConsole(arr, n);
			break;
		case 4:
			delete[] arr;
			break;
		case 5:
			pr = (isDescending(arr, n) && containsPalindrome(arr, n)) ? 1 : 0;
			cout << "pr = " << pr << endl;
			break;
		}
		cout << endl;
	}

	return 0;
}

void inputConsole(int* arr, int n) {

	cout << "Enter array: ";

	for (int* p = arr; p < &arr[n]; p++)
		cin >> *p;

}
void outputConsole(int* arr, int n) {

	cout << "Array: ";

	for (int* p = arr; p < &arr[n]; p++)
		cout << *p << ' ';

	cout << endl;

}
bool isPalindrome(int number) {
	int reversed = 0;
	int original = number;

	while (number > 0) {
		int remainder = number % 10;
		reversed = reversed * 10 + remainder;
		number /= 10;
	}

	return (reversed == original);
}
bool containsPalindrome(int* arr, int n) {
	for (int* p = &arr[0]; p < &arr[n]; p++)
		if (isPalindrome(*p)) return true;

	return false;
}
bool isDescending(int* arr, int n) {
	for (int i = 0; i < n - 1; i++)
		if (arr[i] < arr[i + 1]) return false;

	return true;
}