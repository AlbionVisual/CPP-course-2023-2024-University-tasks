// ������ 6. ������ ��������������� n ����� ����� � ����� �� �����.
// ������������ �������� for.
// ��� ����� n ��������� ������������ (������������) ��� �����.
#include <iostream>
using namespace std;
int main() {
	int n, num, sum = 0;
	do {							// �������� n
		cout << "Enter n: ";	cin >> n;
	} while (n < 0 || n == 0);
	for (int i = 1; i <= n; i = i + 1) {
		cout << "Enter number: ";	cin >> num;
		sum = sum + num;
	}
	cout << "sum =  " << sum << endl;
}
