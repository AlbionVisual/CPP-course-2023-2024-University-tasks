// Пример 6. Использование в функции статической переменной.
#include <iostream>
using namespace std;
void display();			// прототип функции display()
int main() {
	display();	display();	display();
}
void display() {			// определение функции display()
	static int k = 0;	k++;
	cout << "k=" << k << endl;
}
