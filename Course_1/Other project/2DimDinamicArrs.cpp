/*#include <iostream>

using namespace std;

bool isFullEven(int*, int);					// Checks wether all numbers in array are even

int main() {

	int** arr;

	int nx, ny; cout << "Enter array size (x, y): "; cin >> nx >> ny;

	arr = new int* [nx];					// Initialising
	for (int i = 0; i < nx; i++) {
		arr[i] = new int[ny];
	}

	for (int i = 0; i < ny; i++)			// Input
		for (int j = 0; j < nx; j++)
			cin >> arr[j][i];

	cout << "Columns only with evens: ";

	for (int i = 0; i < nx; i++)			// Output
		if (isFullEven(arr[i], ny)) cout << i + 1 << ' ';


	for (int i = 0; i < nx; i++)
		delete[] arr[i];					// Free memory
	delete[]arr;


	return 0;
}

bool isFullEven(int* arr, int n) {

	for (int* i = arr; i < &arr[n]; i++)
		if (*i % 2 != 0) return false;

	return true;
}


//*/

#include <iostream>

using namespace std;

bool isFullEven(int*, int);					// Checks wether all numbers in array are even

int main() {

	int* arr;

	int nx, ny; cout << "Enter array size (x, y): "; cin >> nx >> ny;

	arr = new int[nx * ny];					// Initialising

	for (int i = 0; i < ny; i++)			// Input
		for (int j = 0; j < nx; j++)
			cin >> arr[j * ny + i];

	/*
	for (int i = 0; i < ny * nx; i++)		// Check how data saves
		cout << arr[i] << ' ';
	*/

	cout << "Columns only with evens: ";

	for (int i = 0; i < nx; i++)			// Output
		if (isFullEven(&arr[i * ny], ny)) cout << i + 1 << ' ';

	delete[] arr;					// Free memory

	return 0;
}

bool isFullEven(int* arr, int n) {

	for (int* i = arr; i < &arr[n]; i++)
		if (*i % 2 != 0) return false;

	return true;
}


//*/
