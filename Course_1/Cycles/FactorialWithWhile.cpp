#include <iostream>
using namespace std;
int main() {
	int fact = 1;
	int num, i = 1;
	cout << "Enter num > 0:  ";	cin >> num;		// 5
	while (i <= num) {
		fact = fact * i;
		i = i + 1;
	}
	cout << " fact = " << fact << '\n';			// fact = 120
}
