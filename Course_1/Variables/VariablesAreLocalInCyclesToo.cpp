#include <iostream>
using namespace std;

int main() {
	int sum, i;
	for (int i = 2, sum = 0; i <= 5; i++) // local scoped sum, main sum does not changes
		sum = sum + i;
	cout << sum << endl;
}
