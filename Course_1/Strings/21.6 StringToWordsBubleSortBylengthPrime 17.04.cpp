#include <iostream>
#include <cstring>
using namespace std;

bool isPrime(int);
char** getWords(char*, int&);
void sort(char**, int);

int main() {

	// 6.	¬вести/вывести символьный массив (строку). ¬ыбрать в массиве слова,
	//		длина которых простое число. —оздать массив таких слов и
	//		отсортировать массив в пор€дке возрастани€ длин слов, использу€
	//		эффективную сортировку методом "пузырька" (т.е. без лишних
	//		просмотров элементов массива). ћожно создать дополнительный
	//		одномерный массив длин таких слов в строке.

	// I'm tellin you a joke, yeee here : your mbrella please

	const int N = 100;
	char str[N] = "";
	cout << "Enter your string (max: 100): "; gets_s(str);

	int size = 0;
	char** dict = getWords(str, size);
	sort(dict, size);

	cout << "\nSorted and filtered words:\n";
	for (int i = 0; i < size; i++) {
		cout << dict[i] << endl;
	}

	return 0;
}

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;
	
	if (n != 1) return true;
	else return false;
}
char** getWords(char* str, int &n) {
	char* p = str;
	const char pat[7] = " ,.:()";
	n = (strlen(str) - strlen(str) % 2) / 2;
	char** words = new char*[n];
	int amount = 0;

	do {
		p = p + strspn(p, pat);
		if (isPrime(strcspn(p, pat))) {
			words[amount] = new char[strcspn(p, pat) + 1];
			strncpy_s(words[amount], strcspn(p, pat) + 1, p, strcspn(p, pat));
			amount += 1;
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
			if (strlen(words[j]) > strlen(words[j + 1])) {
				isSorted = false;
				char* buff = words[j];
				words[j] = words[j + 1];
				words[j + 1] = buff;
			}
		}
		if (isSorted) break;
	}
}