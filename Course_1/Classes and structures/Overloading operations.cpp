#include <iostream>

using namespace std;

class LetterSet {
	unsigned int size;
	char* set;

	bool isInSet(char* sym) {
		for (int i = 0; i < size; i++) {

		}
	}

public:

	LetterSet() {
		size = 33;
		set = new char[2 * 33 + 1];
	}
	LetterSet(int n) {
		size = n;
		set = new char[2*33 + 1];
	}
	LetterSet(char* arr, int n) {
		set = arr;
		size = n;
	}
	~LetterSet() { delete[] set; }

	friend ostream& operator<<(ostream& stream, LetterSet set) {
		stream << set.set;
		return stream;
	}
	friend istream& operator>>(istream& stream, LetterSet set) {
		stream >> 
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251  >nul 2>&1");



	int n; cout << "Enter letter anount: "; cin >> n;
	char* arr = new char[2*n + 1];
	cout << "Enter array: ";  cin >> arr;
	cout << "Your arr: " << arr;



	return 0;
}