// ������ 2. ������ ��������������� ����� �� ������� �������������� ���
// �������� �����. ������� �� ������� ������ �������� ������������� �����
// ��� ������ ��������� "No", ���� ������������� ����� �� �����.
#include <iostream>
using namespace std;
int main() {
	int n, num;
	bool flag = 0;
	do {
		cout << "Enter  number: ";  cin >> num;
		if (num < 0) { flag = 1; break; }
	} while (num);
	if (flag) cout << "num = " << num << endl;
	else cout << "No" << endl;
}
