//1.������/������� ���������� ������ mas(n). ����� � ������� ������� � ��� ������,
//����� �������� � �������������� ��� ��������� ���������� � � ������� ���������� ���� ������. 
#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "");

    const int MAX = 100;
    int size, mas[MAX], sum = 0, ind = 0;

    cout << "����� ������ �������: "; cin >> size;
    while (size <= 1 || size > MAX) {
        cout << "��� ����� ������ ���� ����� � ������ 1 � ������ 101. ����� ������: "; cin >> size;
    }

    cout << "����� ������:\n ";
    for (int i = 0; i < size; i++) {
        cin >> mas[i];
    }

    for (int i = 1; i < size; i++) {
        
        if (!sum) {
            if (!(mas[i] % 2)) sum = mas[i - 1] + mas[i];
        }
        else {
            if (!(mas[i] % 2) && mas[i] + mas[i - 1] < sum) {
                sum = mas[i - 1] + mas[i];
                ind = i;
            }
        }
        
    }

    for (int i = 0; i < size; i++) {
        cout << mas[i];
    }

    if (ind) {
        cout << "������� �������: " << mas[ind] << endl;
        cout << "��� ������: " << ind;
    }
    else cout << "�������, ��������������� �������, �����������.";
}