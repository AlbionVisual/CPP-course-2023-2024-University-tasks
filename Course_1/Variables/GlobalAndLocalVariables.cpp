// ������ 4. ���������� � ��������� ���������� � ���������.
#include <iostream>
using namespace std;
int a = 55;
int main() {
	int a = 7; cout << " a = " << a << endl;		// a = 7
	cout << " a = " << ::a << endl;			// a = 55 You can use :: even if a is local only
}
