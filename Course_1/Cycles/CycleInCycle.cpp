// ������ 4. ������� �� ����� ��� ������  ���� �� 0 �� 9.
// ������������ ���� for.
#include <iostream>
using namespace std;
int main() {
	int i, j;
	for (i = 1; i <= 3; i++) {				// ������� ����
		for (j = 0; j < 10; j++)			// ���������� ����
			cout << j << ' ';
		cout << endl;
	}
}
