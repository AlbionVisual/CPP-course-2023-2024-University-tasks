// ������ 1. ������������ ����������� ����. ��������� ���������� 
// �������� �����. ������������ �������� break.
#include <iostream>
using namespace std;
int main() {
	int count(0); 			// ��� count = 0; � ���-�� �������� �����
	char simv;
	while (true) { 			// ����������� ���� 
		cout << "Enter symbol y/n to continue/exit the cycle: \n";
		cin >> simv;
		if (simv == 'n') break;
		count = count + 1;
	}
	cout << "the number of iteration cycle = " << count << endl;
}
