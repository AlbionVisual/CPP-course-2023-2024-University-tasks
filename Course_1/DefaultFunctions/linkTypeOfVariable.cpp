#include <iostream>
using namespace std;

void sumAndTimes(int, int, int&, int&);

int main() {

	int x = 5;
	int& rx = x; // rx - ����� �������� x, ��� ��������� rx ���������� � x � ��������

	int summa, times;
	sumAndTimes(3, 7, summa, times);

	cout << "Sum: " << summa << " times: " << times;

}

void sumAndTimes(int a, int b, int& sum, int& times) {
	sum = a + b;
	times = a * b;
}
