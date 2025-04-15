#include <iostream>
using namespace std;

// Consts
const int SIZE = 40;

// Models
void revString(char [], char []);
bool isPalindrom(char[]);


int main() {

	// 2. ¬ строке слова разделены любым количеством пробелов. ќпределить,
	// €вл€етс€ ли строка палиндромом. 

	char str[SIZE]; // Original string
	cout << "Enter your string: ";
	cin.get(str, SIZE);

	if (isPalindrom(str)) { // If palindrom
		cout << "Your string is palindrom";
	}
	else {
		cout << "Your string isn't palindrom";
	}

	return 0;
}

void revString(char str[], char revStr[]) { // Making reversed string
	for (int i = 0; i < strlen(str); i++) {
		revStr[i] = str[strlen(str) - i - 1];
	}
	revStr[strlen(str)] = '\0';
}

bool isPalindrom(char str[]) { // Checking wether string without spaces palindrom or not
	char revStr[SIZE]; // Reversed string
	revString(str, revStr);

	for (int i = 0, k = 0; i < strlen(str); i++, k++) {
		while (str[i] == ' ') i++;
		while (revStr[k] == ' ') k++;

		if (str[i] != revStr[k]) return false;
	}

	return true;
}