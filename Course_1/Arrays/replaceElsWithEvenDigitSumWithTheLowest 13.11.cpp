#include <iostream>
#include <ctime>

using namespace std;

// Function definitions
bool containNegative(int [], int); 
int findMin(int [], int);
int digitSum(int);

// Copied functions
void fillArray(int arr[], int size, int min, int max) {
	srand(time(NULL));

	for (int i = 0; i < size; i++) arr[i] = rand() % (max - min) + min;
}
void arrInput(int arr[], int size) {
	for (int i = 0; i < size; i++) cin >> arr[i];
}

int main() {

	// 3. Ввести/вывести одномерный массив натуральных чисел mas(n).
	// Найти в массиве элемент с максимальной суммой своих простых делителей,
	// включая их в сумму по одному разу.

	const int SIZE = 10;
	int arr[SIZE];

	fillArray(arr, SIZE, 0, 10000); // Filling array
	// arrInput(arr,SIZE); // Or this way

	cout << endl << "Array before: ";
	for (int i = 0; i < SIZE; i++) cout << arr[i] << ' ';
	cout << endl;

	

	if (!containNegative(arr,SIZE)) { // Wether non-negative
		int minEl = findMin(arr, SIZE);

		for (int i = 0; i < SIZE; i++) { // Replacing nums
			if (digitSum(arr[i]) % 2 == 0) arr[i] = minEl;
		}

		cout << endl << "Array after: "; // Array output 
		for (int i = 0; i < SIZE; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
		
	} else {
		cout << "Array has negative numbers!";
	}



	return 0;
}

bool containNegative(int arr[], int size) { // Wether non-negative array
	for (int i = 0; i < size; i++) if (arr[i] < 0)return true;
	return false;
}

int findMin(int arr[], int size) { // Returns the lowest number in array
	int min = arr[0];
	for (int i = 1; i < size; i++) if (min > arr[i]) min = arr[i];
	return min;
}

int digitSum(int el) { // Counting sum of digits
	int sum = 0;
	while (el) {
		sum += el % 10;
		el /= 10;
	}
	return sum;
}