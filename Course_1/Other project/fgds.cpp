//1.¬вести/вывести одномерный массив mas(n). Ќайти в массиве элемент и его индекс,
//сумма которого с предшествующим ему элементом минимальна и в котором количество цифр чЄтное. 
#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "");

    const int MAX = 100;
    int size, mas[MAX], sum = 0, ind = 0;

    cout << "¬веди размер массива: "; cin >> size;
    while (size <= 1 || size > MAX) {
        cout << "Ёто число должно быть целым и больше 1 и меньше 101. ¬веди другое: "; cin >> size;
    }

    cout << "¬веди массив:\n ";
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
        cout << "»скомый элемент: " << mas[ind] << endl;
        cout << "≈го индекс: " << ind;
    }
    else cout << "Ёлемент, удовлетвор€ющий условию, отсутствует.";
}