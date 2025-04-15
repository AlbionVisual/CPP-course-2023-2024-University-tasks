/* 7. Построить класс для работы с односвязным списком.Элементы списка –
действительные числа. Создать два упорядоченных по невозрастанию списка,
слить их в один(также упорядоченный по невозрас - танию), построив новый
список. */

#include <iostream>
#include <fstream>

using namespace std;

struct Node {    // Тип данных (Node) - элемент односвязного списка
    //public:
    Node* next;  // Следующая ячейка (узел, элемент)
    double data; // Данные этого элемента - действительное число
};

class List {
    //private:
    Node* head = nullptr; // Указатель на первый элемент
    int size = 0;         // Кол-во элементов
public:

    List(double* arr, int n) {           // Конструктор (дин. массив, кол-во эл. в нём)
        for (int i = n - 1; i >= 0; i--) // Итерирование с конца динамического массива
            append(arr[i]);              // Добавление элементов в начало односвязного списка
    };

    void append(double el);                 // Добавление нового элемента в начало односвязного списка
    void clear(Node* sublist = nullptr);    // Реккурсивное удаление всех элементов одн. списка
    // lst1[i]
    double operator[](int n);               // Перегрузка оператора [], извлечение n-го элемента из односвязного списка
    // lst1.len(); => size
    int len() { return size; };             // Возвращает длинну списка
    void print() {                          // Печатает список в консоль
        for (int i = 0; i < size; i++)
            cout << operator[](i) << " ";
    }

    // friend-функции - открывает доступ внутри функции к закрытым полям и методам класса
    friend List combine_lists(const List& lst1, const List& lst2);

    ~List() { clear(); } // Деструктор - очищает память

};

// Методы
void List::append(double el) {
    Node* new_node = new Node{ head, el };
    head = new_node;
    size += 1;
};

void List::clear(Node* sublist) {
    if (!sublist) {
        sublist = head;
        head = nullptr;
        size = 0;
    }
    if (sublist->next) clear(sublist->next);
    delete sublist;
}

// Перегрузка оператора
double List::operator[](int n) {
    if (n >= size) {/*error*/ }
    else {
        Node* p = head, * prev = head;
        for (int i = 0; i <= n; i++) {
            prev = p;
            p = p->next;
        }
        return prev->data;
    }
}

// Дружественная функция
List combine_lists(const List& lst1, const List& lst2) {
    double* res = new double[lst1.size + lst2.size];
    int id = 0;
    Node* p1 = lst1.head, * p2 = lst2.head;
    double num1 = p1->data, num2 = p2->data;
    while (p1 || p2) {
        if ((num2 != NULL && num1 != NULL && num1 > num2) || (num1 && !num2)) {
            res[id++] = num1;
            if (p1 && p1->next) {
                p1 = p1->next;
                num1 = p1->data;
            }
            else { p1 = nullptr; num1 = NULL; }
        }
        else if ((num1 != NULL && num2 != NULL && num1 <= num2) || (num2 && !num1)) {
            res[id++] = num2;
            if (p2 && p2->next) {
                p2 = p2->next;
                num2 = p2->data;
            }
            else { p2 = nullptr; num2 = NULL; }
        }
    }

    List res_list(res, lst1.size + lst2.size);
    return res_list;
}

int main() {

    ifstream fin("input.txt");

    int N; fin >> N;                            // Длинна входного списка 1
    double* arr = new double[N];                // Создание динамического массива длинной N
    for (int i = 0; i < N; i++) fin >> arr[i];  // Ввод чисел в динамический массив

    List lst1(arr, N);                          // Создание и заполнение односвязного списка элементами из динамического массива
    delete[] arr;                               // Удаление динамического массива
    cout << "First list: "; lst1.print(); cout << endl; // endl = end line

    fin >> N;
    arr = new double[N];
    for (int i = 0; i < N; i++) fin >> arr[i];

    List lst2(arr, N);
    delete[] arr;
    cout << "Second list: "; lst2.print(); cout << endl;

    List comb = combine_lists(lst1, lst2);      // Создаём скомбинированный список и сохраняем его в переменную comb
    cout << "Combined list with print " << comb.len() << ": "; comb.print(); cout << endl;

    return 0;
}