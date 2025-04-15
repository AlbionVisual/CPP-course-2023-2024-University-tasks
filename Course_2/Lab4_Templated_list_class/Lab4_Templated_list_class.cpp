/* 7.	Создать шаблон класса для работы с односвязным списком. Применить
шаблон класса для решения задачи № 7 (лаб. работа №  3): Создать два
упорядоченных по невозрастанию списка, слить их в один(также упорядоченный по
невозрастанию), построив новый список. */

#include <iostream>
#include <fstream>

using namespace std;

template<class nodetype>
struct Node {
    Node* next;
    nodetype data;
};

template<class listType>
class List {
    Node<listType>* head = nullptr;
    int size = 0;
public:

    List(listType* arr, int n) { for (int i = n - 1; i >= 0; i--) append(arr[i]); };

    void append(listType el);
    void clear(Node<listType>* sublist = nullptr);
    listType operator[](int n);
    int len() { return size; };
    void print() { for (int i = 0; i < size; i++) cout << operator[](i) << ' '; }

    template<class listType2>
    friend List<listType2> combine_lists(const List<listType2>&, const List<listType2>&);

    ~List() { clear(); }

};

// Методы
template<class listType>
void List<listType>::append(listType el) {
    Node<listType>* new_cell = new Node<listType>{ head, el };
    head = new_cell;
    size += 1;
};

template<class listType>
void List<listType>::clear(Node<listType>* sublist) {
    if (!sublist) {
        sublist = head;
        head = nullptr;
        size = 0;
    }
    if (sublist->next) clear(sublist->next);
    delete sublist;
}

// Перегрузка оператора
template<class listType>
listType List<listType>::operator[](int n) {
    if (n >= size) {/*error*/ }
    else {
        Node<listType>* p = head, * prev = head;
        for (int i = 0; i <= n; i++, prev = p, p = p->next);
        return prev->data;
    }
}

// Дружественная функция
template<class listType>
List<listType> combine_lists(const List<listType>& lst1, const List<listType>& lst2) {
    listType* res = new listType[lst1.size + lst2.size];
    int id = 0;
    Node<listType>* p1 = lst1.head, * p2 = lst2.head;
    listType num1 = p1->data, num2 = p2->data;
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

    List<listType> res_list(res, lst1.size + lst2.size);
    return res_list;
}

int main() {

    ifstream fin("input.txt");

    int N; fin >> N;
    double* arr = new double[N];
    for (int i = 0; i < N; i++) fin >> arr[i];

    List<double> lst1(arr, N);
    delete[] arr;
    cout << "First list: "; lst1.print(); cout << endl;

    fin >> N;
    arr = new double[N];
    for (int i = 0; i < N; i++) fin >> arr[i];

    List<double> lst2(arr, N);
    delete[] arr;
    cout << "Second list: "; lst2.print(); cout << endl;

    List<double> comb = combine_lists(lst1, lst2);
    cout << "Combined list with print " << comb.len() << ": "; comb.print(); cout << endl;

    return 0;
}