// ������ 6. ������������� � ������� ����������� ����������.
#include <iostream>
using namespace std;
void display();			// �������� ������� display()
int main() {
	display();	display();	display();
}
void display() {			// ����������� ������� display()
	static int k = 0;	k++;
	cout << "k=" << k << endl;
}
