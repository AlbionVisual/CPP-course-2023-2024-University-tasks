/* 9. Построить класс для работы с односвязным списком. Создать два списка: List1 и List2.
Проверить, содержатся ли элементы списка List1 в списке List2 в указанном списком List1
порядке. */

#include <iostream>

using namespace std;

template<class listclass>
struct Node {
    Node* next;
    listclass data;
};

template<class listclass>
class List {
    Node<listclass>* head = nullptr;
    int size = 0;

public:

    List() {};
    List(listclass* arr, int n);
    List(const List<listclass>& old);


    void push(listclass el);
    listclass popleft();
    listclass operator[](int n) const;

    void print() const;
    int len() const { return size; }

    template<class listclass2>
    friend bool check_occurance(const List<listclass2>& list1, const List<listclass2>& list2);

};

// Конструкторы
template<class listclass>
List<listclass>::List(listclass* arr, int n) {
    for (int i = n - 1; i >= 0; i--) push(arr[i]);
}

template<class listclass>
List<listclass>::List(const List<listclass>& old) {
    for (int i = old.len() - 1; i >= 0; i--) push(old[i]);
}

// Методы
template<class listclass>
void List<listclass>::push(listclass el) {
    Node<listclass>* new_node = new Node<listclass>{ nullptr, el };
    size += 1;
    if (!head) { head = new_node; }
    else {
        new_node->next = head;
        head = new_node;
    }
}

template<class listclass>
listclass List<listclass>::popleft() {
    if (size <= 0) { /* error */ }
    else {
        Node<listclass>* p = head->next;
        listclass ans = head->data;
        delete head;
        head = p;
        return ans;
    }
}

template<class listclass>
void List<listclass>::print() const {
    Node<listclass>* p = head;
    while (p) {
        cout << p->data << ' ';
        p = p->next;
    }
}

// Перегрузка операторов
template<class listclass>
listclass List<listclass>::operator[](int n) const {
    if (n >= size) { /* error */ }
    else {
        Node<listclass>* p = head;
        for (int i = 0; i < n; i++, p = p->next);
        return p->data;
    }
}

// Функции
template<class listclass2>
bool check_occurance(const List<listclass2>& list1, const List<listclass2>& list2) {
    Node<listclass2>* p1 = list1.head;
    Node<listclass2>* p2 = list2.head;

    while (p1 && p2) {
        if (p1->data == p2->data) {
            p1 = p1->next;
            if (!p1) return true;
        }
        p2 = p2->next;
    }

    return false;
}

int main() {

    int* arr = new int[12] {1, 2, 3, 2, 4, 6, 1, 6, 2, 4, 5, 3};
    List<int> list1(arr, 3);
    List<int> list2(&arr[3], 9);

    cout << "List1: "; list1.print();
    cout << endl << "List2: "; list2.print();
    cout << "\nCheck occurance: " << (check_occurance(list1, list2) ? "true" : "false") << endl;

    return 0;
}