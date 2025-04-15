#include <iostream>
using namespace std;

bool isPalindrom(int);
int countingNumOfDigits(int num);
bool isEven(int num);

int main() {

	// Ввести/вывести одномерный массив mas(n). Вставить в массив заданное
	// число (вводится) после первого элемента-палиндрома с нечётным
	// количеством цифр

	const int SIZE = 10;
	int arr[SIZE+1];

	int numToAdd;
	cout << "Write number you want to add: "; cin >> numToAdd;

	cout << "Write " << SIZE << " elements of your array: "; for (int i = 0; i < SIZE; i++) cin >> arr[i];

	int searchingIndex = -1;

	for(int i =0; i < SIZE;i++)
		if (!isEven(countingNumOfDigits(arr[i])) and isPalindrom(arr[i])) {
			searchingIndex = i;
			break;
		}
	
	if (searchingIndex != -1) {

		for (int i = SIZE; i > searchingIndex; i--) {
			arr[i] = arr[i - 1];
		}
		arr[searchingIndex+1] = numToAdd;

		cout << "Edited array: ";
		for (int i = 0; i < SIZE + 1; i++) {
			cout << arr[i] << ' ';
		}

	} else cout << "There is no numbers compatible with your conditions";

	return 0;
}

bool isPalindrom(int n) {
	int temp = n, rev = 0;
	
	while (temp > 0) {
		int dig = temp % 10;
		rev = 10 * rev + dig;
		temp = temp / 10;
	}
	
	if (rev == n) return true;
	else return false;

}

int countingNumOfDigits(int num) {
	int counter = 0;

	while (num) {
		num /= 10;
		counter++;
	}

	return counter;
}

bool isEven(int num) {
	if (num % 2 == 0)return true;
	else return false;
}