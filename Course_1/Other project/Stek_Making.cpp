#include <iostream>

using namespace std;

const  int MAX_STRING_LINE = 100;

struct Node {										// Cell of Stack memory
	char    d[MAX_STRING_LINE];
	Node*	link;
};

int main() {

	char str[MAX_STRING_LINE];						// Input
	cout << "Enter a string: "; cin.get(str, MAX_STRING_LINE);

	// cout << "You entered: " << str << endl;		// Check if input / output works as well as you need

	int start = -1;

	Node* el = new Node();							// Make first element - stop-element
	(*el).link = el;

	for (int i = 0; i < MAX_STRING_LINE; i++) {

		if (str[i] == ' ' or str[i] == '.' or str[i] == ',' or str[i] == ':' or str[i] == ';' or str[i] == '!' or str[i] == '?' or str[i] == '-' or str[i] == '(' or str[i] == ')') {
													// When we find stop-symbol - make new element of stack
			if (i - start != 1) {
				Node* buff = el;
				el = new Node();
				(*el).link = buff;
			}

			start = i;

			continue;
		}
		(* el).d[i - start - 1] = str[i];			// All not stop symbols will be written here to stack elements
	}

	/*Node* buff = (*el).link;
	delete el;										// Last element was made accsidently
	el = buff;//*/

	while ((*el).link != el) {						// While we don't reach stop-element

		cout << (*el).d << ' ';						// Output

		Node* buff = (*el).link;
		delete el;									// Free memory after stacking
		el = buff;

	}

	cout << (*el).d;								// Free memory for stop-element
	delete el;

	return 0;
}