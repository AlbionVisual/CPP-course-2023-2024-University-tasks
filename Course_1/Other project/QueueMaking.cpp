#include <iostream>

using namespace std;

const  int MAX_STRING_LINE = 100;

struct Cell {										// Cell of Stack memory
	char    d[MAX_STRING_LINE];
	Cell* link;
};

int main() {

	char str[MAX_STRING_LINE];						// Input
	cout << "Enter a string: "; cin.get(str, MAX_STRING_LINE);

	// cout << "You entered: " << str << endl;		// Check if input / output works as well as you need

	int start = -1;



	Cell* el = new Cell();
	Cell* first = el;

	int i = 0; while (str[i] != '\0') i++; str[i] = ' ';

	for (int i = 0; i < MAX_STRING_LINE; i++) {

		if (str[i] == ' ' or str[i] == '.' or str[i] == ',' or str[i] == ':' or str[i] == ';' or str[i] == '!' or str[i] == '?' or str[i] == '-' or str[i] == '(' or str[i] == ')') {
			// When we find stop-symbol - make new element of stack
			if (i >= 3 and str[i - 1] == 'z' and str[i - 2] == 'y' and str[i - 3] == 'x') { // Just a filter
				
				for (int j = i - start - 1; (*el).d[j] != '\0'; j++) { // delete rubish chars
					(*el).d[j] = '\0';
				}

				if (i - start != 1) {
					Cell* buff = new Cell();
					(*el).link = buff;				// Make new cell
					el = buff;
				}
			}

			start = i;

			continue;
		}
		(*el).d[i - start - 1] = str[i];			// All not stop symbols will be written here to queue elements
	}

	(*el).link = el;								// Make a stop-element (that don't contain usefull information)
	el = first;

	while ((*el).link != el) {						// While we don't reach stop-element

		cout << (*el).d << ' ';						// Output

		Cell* buff = (*el).link;
		delete el;									// Free memory after queueing
		el = buff;

	}

	delete el;										// Free memory for stop-element

	return 0;
}