#include <iostream>
using namespace std;

int main() {

	// Initialising and creating
	char simv = 'A';		// символьная переменная simv со значением 'A'

	// Input and output
	char simv;		cin >> simv;
	cout << "simv = " << simv << endl;

	char a, b;
	cin >> a >> b;					// введём 53
	cout << a << ' ' << b << ' '				// a = 5, b = 3
		<< a % b << ' ' << a / b << '\n';		// a(53) % b(51) = 2, a / b = 1

	char simv;
	cout << "Enter simvol: ";	simv = cin.get();			// введём   A
	cout << " simv = " << simv << endl;				// simv = A

	cout << "Enter simvol: ";	char simv = getchar();		// введём   D
	cout << " simv = " << simv << endl;				// simv = D

	cin.ignore();			// "чистим" поток для getline()

	char simv = 'f';
	cout.put(simv);						// f
	cout << "\nsimv =  " << simv << endl;			// simv = f;

	// Usage
	int k = 1;
	for (simv = 'A'; simv <= 'Z'; simv++) {
		for (int j = 1; j <= k; j++)
			cout << simv;
		cout << endl;
		k++;
	}
	cout << endl;


	// ---- Arrays (strings) ----
	// Creating and initializing
	char str[20];	// максимальное число символов может  быть 19

	char str[6] = "HELLO";	// автоматически добавляется 
					// в конец массива символ '\0'.
	char str[] = "HELLO";		// размер массива можно не указывать
	char str[] = { 'H', 'E', 'L', 'L', 'O', '\0' };
	char str[] = { 'h', 'e', 'l', 'l', 'o', '\0' };

	char str[10];	//str = "Hello";		// нельзя!!!
	char str1[10], str2[10] = "ffff";
	//str1 = str2;						// нельзя!!!


	// Input output arrays
	char str[10];
	cout << "Enter row: ";		cin >> str;		// введём ABCDEF
	cout << "str = " << str << endl;				// ABCDEF

	char str[20];
	cin >> str;					// введём, например, 111 2222
	cout << "str = " << str << endl;		// 111

	// gets_s(имя_массива);
	const int MAX = 20;
	cin.get(str, MAX);
	cin.getline(str, MAX);




	return 0;
}