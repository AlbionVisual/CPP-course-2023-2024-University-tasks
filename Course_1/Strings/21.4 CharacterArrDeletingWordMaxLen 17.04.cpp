#include <iostream>
#include <cstring>

using namespace std;

int main() {

	/* 80
I'm tellin you a joke, yeee here: your rella please
	*/

	int n;
	cout << "Enter max amount of symbols: "; cin >> n;
	char* pstr = new char[n];
	cin.ignore();
	cout << "Enter sting: "; gets_s(pstr, n);

	const char pat[7] = " ,.:()";
	int maxlen = 0;
	char* p = pstr;
	char** maxWords = new char* [(n + n % 2) / 2];
	short id = 0;

	do {
		p = p + strspn(p, pat);
		char* word = new char[strcspn(p, pat) + 1];
		strncpy_s(word, strcspn(p, pat) + 1, p, strcspn(p, pat));
		if (strlen(word) == maxlen) {
			maxWords[id] = p;
			id += 1;
		}
		else if (strlen(word) > maxlen) {
			for (int i = 0; i < id; i++) delete maxWords[i];
			id = 0;
			maxlen = strlen(word);
			maxWords[id] = p;
			id += 1;
		}
		delete[] word;
		p = p + strcspn(p, pat);
	} while (*p);



	for (int i = 0; i < id; i++) {
		for (int j = 0; j < maxlen; j++)
			cout << maxWords[i][j];
		cout << ' ';
	}

	if (id > 1) {
		p = maxWords[0];
		do {
			p = p + maxlen;
			p++;
		} while (*(p + maxlen));
	}
	else {
		p = maxWords[0];
		for (int i = 0; i < maxlen; i++) {
			*p = '*';
		}
	}

	cout << endl << pstr;

	for (int i = 0; i < id; i++)
		delete maxWords[i];
	
	delete[] maxWords;
	delete[] pstr;

	return 0;
}