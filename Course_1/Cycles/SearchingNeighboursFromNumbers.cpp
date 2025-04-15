#include <iostream>
using namespace std;

int main() {

	// ¬вод n чисел и подсчЄт кол-ва одинаковых подр€д идущих чисел

	int n, prev, next, k = 0;
	cout << "Enter number of integers: ";
	cin >> n;

	while (n < 2) {
		cout << "Try again: ";
		cin >> n;
	} 

	// Getting first value as prev:
	cout << "Enter " << n << " numbers:\n";
	cin >> prev;
	n=n-1;

	// Getting other values and comparing with prev
	while (n > 0) {
		cin >> next;
		if (next == prev) k=k+1;
		prev = next;
		n=n-1;
	}

	cout << "Number of equals: " << k;

	return 0;
}