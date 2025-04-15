/*  8. Создать шаблон класса для работы с бинарным деревом.Применить его для сортировки
действительных чисел и строк, вводимых с клавиатуры или из файла.  */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template<class data_type>
struct Node {
    Node* left;
    Node* right;
    data_type data;
};

template<class data_type>
class Tree {
    Node<data_type>* head = nullptr;

public:

    Tree() {}
    Tree(data_type* arr, int n);

    void push(data_type el);
    void operator+=(data_type el) { this->push(el); };
    void lcr(Node<data_type>* subtree = nullptr);
    void rcl(Node<data_type>* subtree = nullptr);
    void clear(Node<data_type>* subtree = nullptr);

    ~Tree();
};

template<class data_type>
Tree<data_type>::Tree(data_type* arr, int n) {
    for (int i = 0; i < n; i++) {
        push(arr[i]);
    }
};

template<class data_type>
void Tree<data_type>::push(data_type el) {
    Node<data_type>* new_cell = new Node<data_type>{ nullptr, nullptr, el };

    if (!head) { head = new_cell; }
    else {
        Node<data_type>* pointer = head, * prev = head;

        while (pointer) {
            if (pointer->data <= el) {
                prev = pointer;
                pointer = pointer->left;
            }
            else {
                prev = pointer;
                pointer = pointer->right;
            }
        }

        if (prev->data <= el) prev->left = new_cell;
        else prev->right = new_cell;
    }
}

template<class data_type>
void Tree<data_type>::lcr(Node<data_type>* subtree) {
    if (!subtree) subtree = head;
    if (subtree->left) lcr(subtree->left);
    cout << subtree->data << ", ";
    if (subtree->right) lcr(subtree->right);
}

template<class data_type>
void Tree<data_type>::rcl(Node<data_type>* subtree) {
    if (!subtree) subtree = head;
    if (subtree->right) rcl(subtree->right);
    cout << subtree->data << ", ";
    if (subtree->left) rcl(subtree->left);
}

template<class data_type>
void Tree<data_type>::clear(Node<data_type>* subtree) {
    if (!subtree) subtree = head;
    if (subtree->left) clear(subtree->left);
    if (subtree->right) clear(subtree->right);
    delete subtree;
}

template<class data_type>
Tree<data_type>::~Tree() {
    clear();
}

int main() {

    ifstream fin("input.txt");
    int N; fin >> N; cout << "Number array:\n\tAmount is " << N << endl;

    Tree<int> graph;
    cout << "\tEntered values: ";
    for (int i = 0; i < N; i++) {
        int el; fin >> el; cout << el << " ";
        graph.push(el);
    }
    cout << endl;

    cout << "\tLeft-hand bypass: "; graph.lcr(); cout << endl;
    cout << "\tRight-hand bypass: "; graph.rcl(); cout << endl;

    fin >> N; cout << "String array:\n\tAmount is " << N << endl;

    Tree<string> graph2;
    cout << "\tEntered values:\n\t";
    fin.ignore();
    for (int i = 0; i < N; i++) {

        string el; getline(fin, el); cout << "\t" << el << "\n\t";
        graph2.push(el);
    }

    cout << "Left-hand bypass: "; graph2.lcr(); cout << endl;
    cout << "\tRight-hand bypass: "; graph2.rcl(); cout << endl;


    // const short N = 10;
    // int* arr = new int[N] {1, 56, 7, 345, 567, 0, 56, 846, -35, 342};
    // Tree graph(arr, N);
    // cout << "Left-hand bypass: "; graph.lcr(); cout << endl;
    // cout << "Right-hand bypass: "; graph.rcl(); cout << endl;

    return 0;
}