#include <iostream>
#include <cstring>

using namespace std;

char** getWords(char*, int&);
bool isPalindrom(char*);
void sort(char**, int);

int main() {

	// 5.	Ввести/вывести символьный массив (строку). Выбрать в массиве
	//		слова-палиндромы, и длина которых чётная. Создать массив таких
	//		слов и отсортировать его в алфавитном порядке, используя
	//		эффективную сортировку методом "пузырька" (т.е. без лишних
	//		просмотров элементов массива).

	/* 80
I'm tellin you a joke, yeee here : your mbrella please
	*/

	int n;
	cout << "Enter max amount of symbols: "; cin >> n;
	char* pstr = new char[n + 1];
	cin.ignore();
	cout << "Enter your string: "; gets_s(pstr, n+1);

	int size = 0;
	char** dict = getWords(pstr, size);
	sort(dict, size);

	cout << "\nSorted and filtered words:\n";
	for (int i = 0; i < size; i++) {
		cout << dict[i] << endl;
	}

	return 0;
}

bool isPalindrom(char* str) {
	char* start = str, *end = str + strlen(str) - 1;

	while (start < end) {
		if (*start != *end) return false;
		start += 1;
		end -= 1;
	}
	return true;
}
char** getWords(char* str, int& n) {
	char* p = str;
	const char pat[7] = " ,.:()";
	n = (strlen(str) - strlen(str) % 2) / 2;
	char** words = new char* [n];
	int amount = 0;

	do {
		p = p + strspn(p, pat);
		if (strcspn(p, pat) % 2 == 0) {

			char* word = new char[strcspn(p, pat) + 1];
			strncpy_s(word, strcspn(p, pat) + 1, p, strcspn(p, pat));
			if (isPalindrom(word)) {
				words[amount] = word;
				amount += 1;
			}
			else {
				delete[] word;
			}
		}
		p = p + strcspn(p, pat);
	} while (*p);
	n = amount;
	return words;
}
void sort(char** words, int n) {
	bool isSorted;
	for (int i = 0; i < n; i++) {
		isSorted = true;
		for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(words[j], words[j+1]) < 0) {
				isSorted = false;
				char* buff = words[j];
				words[j] = words[j + 1];
				words[j + 1] = buff;
			}
		}
		if (isSorted) break;
	}
}