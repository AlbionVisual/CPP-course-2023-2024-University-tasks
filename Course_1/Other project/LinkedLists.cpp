#include <iostream>

using namespace std;

// Определение структуры узла списка
struct Node {
    int data;       // Значение узла
    Node* next;     // Указатель на следующий узел
};

// Функция для добавления нового узла в конец списка
void append(Node** headRef, int value) {
    // Создаем новый узел
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    // Если список пуст, делаем новый узел головным
    if (*headRef == nullptr) {
        *headRef = newNode;
        return;
    }

    // Иначе находим последний узел и добавляем новый узел после него
    Node* lastNode = *headRef;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Функция для вывода содержимого списка
void display(Node* head) {
    Node* currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

// Есть ли в списке определённый элемент
bool contains(Node* head, int num) {
    Node* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->data == num)
            return true;
        currentNode = currentNode->next;
    }
    return false;
}

Node* combine(Node* head1, Node* head2) {

    Node* L = nullptr;

    for (Node* i = head1; i != nullptr; i = i->next) {
        if (!contains(head2, i->data)) {
            append(&L, i->data);
        }
    }
    for (Node* i = head2; i != nullptr; i = i->next) {
        if (!contains(head1, i->data)) {
            append(&L, i->data);
        }
    }

    return L;
}

int main() {
    // Инициализация пустого списка
    Node* L1 = nullptr; Node* L2 = nullptr;

    int n1; cout << "Enter amount of elements in first list: "; cin >> n1;

    cout << "Enter list 1: ";
    for (int i = 0; i < n1; i++) {
        int el;
        cin >> el;
        append(&L1, el);
    }

    int n2; cout << "Enter amount of elements in second list: "; cin >> n2;

    cout << "Enter list 2: ";
    for (int i = 0; i < n2; i++) {
        int el;
        cin >> el;
        append(&L2, el);
    }

    // Вывод содержимого списков
    cout << "First list: ";
    display(L1);
    cout << "Second list: ";
    display(L2);

    cout << "Answer: "; display(combine(L1,L2));

    return 0;
}