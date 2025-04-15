#include <iostream>
using namespace std;
int main() {
	int fact = 1, num;
	cout << "Enter number > 0:  ";	cin >> num;	// 5
	for (int i = 1; i <= num; i = i + 1)
		fact = fact * i;
	cout << "fact = " << fact << '\n';			// 120
}
