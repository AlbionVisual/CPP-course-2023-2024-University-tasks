#include <iostream>
#include <ctime>

using namespace std;

void enterArray(int arr[], int n, int min, int max) {

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (max - min) + min;
	}

};

int main() {

	int seed = 1, num = 5, max = 23, min = 3;
	srand(seed);

	for (int i = 0; i < num;i++)cout << rand() % (max - min) + min << ' ';
	cout << endl;

	const int SIZE = 10;
	int arr[SIZE];

	enterArray(arr, SIZE, 15, 30);

	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << ' ';
	}

}