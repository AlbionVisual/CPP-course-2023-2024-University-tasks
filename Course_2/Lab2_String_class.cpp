/*  8. Определить класс «Строка» – String длины n. Написать несколько конструкторов,
в том числе конструктор копирования. Реализовать методы для выполнения конкатенации
строк, извлечения символа из заданной позиции, сравнения строк. Перегрузить операции
сложения, индексирования, отношения, добавления, присваивания для данного класса.
    Создать массив объектов и передать его в функцию, которая выполняет сортировку
строк.  */

#include <iostream>

using namespace std;

class String {
    char* str;
    int n = 0;
public:
    String() {};
    String(const char* s);
    String(const String& str2);

    int len() { return n - 1; };
    void show() { cout << str; };
    char* get() { return str; };

    String& operator=(String str2);
    String operator+(String str2);
    char operator[](int ind);
    String operator+=(String str2);
    bool operator==(String str2);
    bool operator!=(String str2) { return !(*this == str2); };
    bool operator>=(String str2);
    bool operator>(String str2) { return (*this >= str2) && (*this != str2); };
    bool operator<=(String str2) { return !(*this > str2); };
    bool operator<(String str2) { return !(*this >= str2); };

    ~String() { delete[]str; };
};


// ---------- Перегрузка операторов ----------
String& String::operator=(String str2) { // Перегрузка оператора присваивания
    if (n != 0) delete[] str;
    str = new char[str2.len() + 1];
    n = str2.len() + 1;
    for (int i = 0; i < n; i++) {
        str[i] = str2.str[i];
    }
    return *this;
}

String String::operator+(String str2) { // Конкатенация строк

    char* st1 = str;
    int n1 = n;
    char* st2 = str2.get();
    int n2 = str2.len() + 1;
    char* st3 = new char[n1 + n2];
    for (int i = 0; i < n1 - 1; i++) {
        st3[i] = st1[i];
    }
    for (int i = 0; i < n2; i++) {
        st3[i + n1 - 1] = st2[i];
    }

    String rab(st3);

    return rab;
}

char String::operator[](int ind) { // Извлечение элемента по индексу
    if (ind >= n - 1) {
        cout << "\nString index out of range" << endl;
    }
    return str[ind];
}

String String::operator+=(String str2) {
    *this = *this + str2;
    return *this;
}

// ---------- Перегрузка операторов сравнения ----------
bool String::operator==(String str2) { // Сравнение двух строк
    if (n - 1 != str2.len()) return false;

    for (int i = 0; i < n; i++) {
        if (str[i] != str2.get()[i]) return false;
    }
    return true;
}

bool String::operator>=(String str2) {
    int n1 = n, n2 = str2.len() + 1, nm;
    if (n1 < n2) { nm = n1; }
    else { nm = n2; }
    for (int i = 0; i < nm; i++) {
        if (str[i] != str2.get()[i]) {
            if (str[i] > str2.get()[i]) return true;
            else return false;
        }
    }
    if (n1 >= n2) return true;
    else return false;
}

// ---------- Конструкторы ----------
// String::String() {
//     char* buf = new char[100];
//     cin.ignore();
//     cin.getline(buf, 100);
//     for (char* p = buf; *p; p++, n++) {}
//     n += 1;
//     str = new char[n];
//     for (int i = 0; i < n; i++) {
//         str[i] = buf[i];
//     }
//     cout << str << endl;
//     // cout << buf << endl;
// }

String::String(const char* s) { // Конструктор с массива символов
    const char* p = s;
    n = 0;
    for (;*p; p++, n++) {}
    n += 1; // copy \0 element at end too
    str = new char[n]; p = s;
    for (int i = 0; i <= n; i++, p++) {
        str[i] = *p;
    }

}

String::String(const String& str2) { // Конструктор копирования
    n = str2.n;
    str = new char[n];
    for (int i = 0; i < n; i++) {
        str[i] = str2.str[i];
    }
}

// ---------- Функции обработки ----------
void sort(String* arr, int n) {
    for (int i = 0; i < n; i++) {
        int id = i;
        while (id >= 1 && arr[id] < arr[id - 1]) {
            String buf = arr[id]; arr[id] = arr[id - 1]; arr[id - 1] = buf;
            id -= 1;
        }
    }
}

// ---------- Тестирование ----------
void test() {
    // Конструкторы
    String a("str1");
    String b = a + String(a);                           // Оператор присваивания и суммы

    cout << "a:"; a.show(); cout << ' ' << a.len() << endl;
    cout << "b:"; b.show(); cout << ' ' << b.len() << endl;

    // Перегрузка операторов
    String sum = a + b;                                 // Конкатенация, присваивание
    cout << "sum:"; sum.show(); cout << ' ' << sum.len() << endl;

    cout << sum[4] << sum[5] << "..." << sum[11];       // Извлечение части
    sum[12];

    sum += String("EndHere)");                          // Конкатенация + присваивание

    cout << sum[4] << sum[5] << "..." << sum[11] << sum[12] << endl;

    cout << "sum:"; sum.show(); cout << ' ' << sum.len() << endl;

    // Перегрузка операторов сравнения
    cout << "a == a: " << (a == a) << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a == \"str2\": " << (a == String("str2")) << endl;
    cout << "a != \"str2\": " << (a != String("str2")) << endl;
    cout << "a == \"str1\": " << (a == String("str1")) << endl;

    cout << "a >= a: " << (a >= a) << endl;
    cout << "a > a: " << (a > a) << endl;
    cout << "a >= b: " << (a >= b) << endl;
    cout << "b >= a: " << (b >= a) << endl;
    cout << "a >= \"str2\": " << (a >= String("str2")) << endl;
}

int main() {

    test();

    // ---------- Задача с массивом ----------
    String* arr = new String[5]{                // Создание массива
        String("str1"),
        String("str8"),
        String("str17"),
        String("str4"),
        String("str5")
    };

    sort(arr, 5);                               // Сортировка по возрастанию

    for (int i = 0; i < 5; i++) {
        arr[i].show(); cout << endl;
    }

    return 0;
}
