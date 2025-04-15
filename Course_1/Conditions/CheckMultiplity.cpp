#include <iostream>
using namespace std;

int main() {
	int	a, b;
	cout << "Enter a, b: ";
	cin >> a >> b;
	cout << " a=" << a << " b=" << b << endl;
	if (a % b == 0) cout << "a is multiply of b\n";
	else cout << "a no multiply of b\n";
}