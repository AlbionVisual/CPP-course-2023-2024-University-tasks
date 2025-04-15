#include <iostream>

using namespace std;

void inputConsole(int*, int);								// ¬вод массива с консоли
void outputConsole(int*, int);								// ¬ывод массива в консоль	
void removeChain(int*, int&);								// ”даление максимальной цепочки подр€д идущих элементов

int main() {

	// 3.	¬вести/вывести одномерный массив натуральных чисел размера n. ”далить в
	//		исходном массиве цепочку максимальной длины идущих подр€д элементов,
	//		значени€ которой расположены по возрастанию (нули не учитывать).
	//		ƒополнительный массив не использовать. 

	//		“естовые массивы:
	// 
	//		2 3 0 5 0 6 1 2 3 4 0 5 6 7 2 0 4 1 5
	// 
	//		5 4 3 2 3 0 5 -10 -5 0 1 4 20 1 2 3 1 0
	// 
	//		5 4 3 2 3 4 5 0 10 100
	//

	int choice = -1;
	int n; int* arr = 0;									// —оздание переменных

	while (choice != 6) {
		cout << "Create --> 1, Reinit --> 2,\nPrint --> 3, Delete --> 4,\nRemove chain --> 5, End --> 6\nSelected: ";
		cin >> choice;
		switch (choice) {									// ћеню
		case 1:
			cout << "Enter size: "; cin >> n;
			arr = new int[n];
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
			removeChain(arr, n);
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
void removeChain(int* arr, int& n) {

	int maxSize = 0, start = 0;
	for (int id = 0, i = 0; i < n - 1; i++) {
		if (arr[i] >= arr[i + 1] && arr[i + 1] != 0) {
			if (i - id > maxSize) {
				maxSize = i - id;
				start = id + 1;
			}
			id = i;
		}
	}

	for (int* p = &arr[start]; p < &arr[n]; p++)
		*p = *(p + maxSize);

	n -= maxSize;

	cout << "Removed!";

}