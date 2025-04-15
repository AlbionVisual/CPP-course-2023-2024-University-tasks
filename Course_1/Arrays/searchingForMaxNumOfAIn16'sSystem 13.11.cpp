#include <iostream>
#include <iomanip>
using namespace std;

// Function definitions
int maxNumOfA(int [], int, int &);
int maxNumOfA(int[], int);
int numOfA(int);
void swapEl(int [], int, int);

// Copied funcs
void arrInput(int arr[], int size) {
	for (int i = 0; i < size; i++) cin >> hex >> arr[i];
}

int main() {

	// 1. Если в массиве целых чисел mas(n) нет отрицательных элементов,
	// каждый элемент массива, сумма цифр которого чётная, заменить 
	// минимальным элементом массива. 

	const int SIZE = 5;
	int arr[SIZE], ind = -1;

	cout << endl << "Input your array: "; arrInput(arr, SIZE); // Array input

	int max = maxNumOfA(arr, SIZE, ind); // Searching for element with condition

	if (ind != -1) {
		swapEl(arr, 0, ind); // Swaping elements
		
		cout << endl << "Your array after: "; // Array output
		for (int i = 0; i < SIZE; i++) cout << hex << arr[i] << ' ';
		cout << endl;
	} else {
		cout << "There is no elements matching your conditions";
	}

	return 0;
}

int numOfA(int num) { // counting number of a in 16 system

	int count = 0;

	while (num) {
		if (num % 16 == 10) count++; 
		num /= 16;
	}

	return count;
}
int maxNumOfA(int arr[], int size, int &ind) { //counting max amount of a in array
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (numOfA(arr[i]) > max) {
			max = numOfA(arr[i]);
			ind = i;
		}
	}

	return max;
}
int maxNumOfA(int arr[], int size) {
	int max = 0;
	for (int i = 0; i < size; i++) if (numOfA(arr[i]) > max) max = numOfA(arr[i]);
	return max;
}
void swapEl(int arr[], int a, int b) {
	int buff = arr[a];
	arr[a] = arr[b];
	arr[b] = buff;
}