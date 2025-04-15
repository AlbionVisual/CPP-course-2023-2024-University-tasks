#include <iostream>
using namespace std;

int main() {

	// Вывод классности введённой отметки при помощи switch

	int mark;
	cout << "Enter mark: ";	cin >> mark;

	switch (mark) {
	case 5:
		cout << "Excelent mark!";

	case 4:
		cout << "Good mark";
	case 3:
	case 2:
	case 1:
		cout << "Bad mark";
	}


	return 0;
}