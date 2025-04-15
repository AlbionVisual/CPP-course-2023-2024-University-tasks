#include <iostream>

using namespace std;

int main() {

	int* ptr;
	// ptr = new int; // Выделяет 4 байта памяти, прямого имени нет, только указатели
	// Операция new запрашивает занимание памяти по мере выполнения программы
	// а не компиляции

	// Или так:
	ptr = new int(5); // Загружает 5 в нововыделенную память

	// cout << *ptr;

	delete ptr;
	// А delete - освобождает память

	int val1 = 10, val2 = 20;
	ptr = new int(val1);
	cout << "val1 = " << val1 << endl;
	cout << "*ptr = " << *ptr << endl;
	val1 = 5;
	cout << "val1 = " << val1 << endl;
	cout << "*ptr = " << *ptr << endl;
	*ptr = 7;
	cout << "val1 = " << val1 << endl;
	cout << "*ptr = " << *ptr << endl;
	delete ptr;

	// А теперь массивы:
	int n; cin >> n;
	ptr = new int[n] {1, 2, 3, 4, 5, 6};
	for (int i = 0; i < n; i++)
		cout << ptr[i] /* индексная форма */ << ' ';// << *(ptr + i) /* Адресная форма */;

	delete[] ptr;

	return 0;
}