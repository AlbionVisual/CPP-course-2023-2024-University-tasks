#include <iostream>

using namespace std;

class Number {
	unsigned int n;
	int max;
	void calcMax();
public:
	Number() { n = 0; calcMax(); };
	Number(int n0) { n = n0; calcMax(); };
	void set(int);
	void set();
	int get();
	int getMax();

};

int main() {

	int n; cout << "Enter amount of numbers: "; cin >> n; cout << endl;
	Number* nums = new Number[n];

	for (int i = 0; i < n; i++)
		nums[i].set();
	cout << endl;

	cout << "Numbers with max > 1: ";
	int min = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i].getMax() > 1) cout << nums[i].get() << ", ";

		if (nums[min].getMax() > nums[i].getMax()) min = i;
	}

	cout << "\n\nMinimum max in number with index: " << min << endl;



	delete[] nums;

	return 0;
}

void Number::set(int n) {
	this->n = n;
	calcMax();
}
void Number::set() {
	cout << "Enter natural number: "; cin >> this->n;
	calcMax();
}
int Number::get() {
	return n;
}
int Number::getMax() {
	return max;
}

void Number::calcMax() {
	int k = n;
	int maxDigit = -1;
	int amount = 0;
	while (k) {
		if (k % 10 == maxDigit) amount += 1;
		else if (k % 10 > maxDigit) {
			amount = 1;
			maxDigit = k % 10;
		}
		k /= 10;
	}
	max = amount;
}