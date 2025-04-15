#include <iostream>

using namespace std;

int main() {
	
	int a, b, rab;
	cout << "Enter a and b: ";
	cin >> a >> b;
	
	rab = a;
	a = b;
	b = rab;
	
	cout << "a: " << a << ", b: " << b;

	return 0;
}