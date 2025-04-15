/*  8. Построить класс для работы с односвязным списком. Элементы списка – слова.
Создать список, содержащий некоторую последова-тельность слов. Заменить в списке
каждое вхождение заданного слова другим (также заданным).  */

#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    char* word;
    Node* link;
};

class WordList {
    Node* head = nullptr;
    int amount = 0;
public:
    WordList() {};

    void push(char* word);
    char* pop(int ind = NULL);
    int len() { return amount; }
    void clear();
    void replace(char* remove_word, char* new_word);

    char* operator[](int ind);

    ~WordList();

private:
    bool is_equal(char* word1, char* word2);
    char* word_copy(char* word1);
};

// ---------- Методы ----------
void WordList::push(char* word) {
    if (!head) { head = new Node{ this->word_copy(word), nullptr }; }
    else {
        Node* p = head;
        while (p->link) {
            p = p->link;
        }
        p->link = new Node{ this->word_copy(word), nullptr };
    }
    amount += 1;
}

char* WordList::pop(int ind) {
    if (ind == NULL) ind = amount - 1;
    if (ind >= amount) {
        cout << "List index out of range\n";
        return "";
    }

    Node* p = head;
    if (ind == 0) { head = head->link; }
    else {
        p = p->link;
        Node* prev = head;
        for (int i = 1; i < ind; i++) {
            prev = p;
            p = p->link;
        }
        prev->link = p->link;
    }
    amount -= 1;
    return p->word;
}

void WordList::clear() {
    while (amount > 0) {
        this->pop();
    }
}

// ---------- Перегрузка операторов ----------
char* WordList::operator[](int ind) {
    Node* p = head;
    for (int i = 0; i < ind; i++) {
        if (!p->link) {
            cout << "\nList index out of range\n";
            return "";
        }
        p = p->link;
    }
    return p->word;
}

void WordList::replace(char* remove_word, char* new_word) {
    Node* p = head;
    for (int i = 0; i < amount; i++) {
        if (is_equal(p->word, remove_word)) {
            p->word = this->word_copy(new_word);
        }
        p = p->link;
    }
}

bool WordList::is_equal(char* word1, char* word2) {
    char* p1, * p2;
    for (p1 = word1, p2 = word2; *p1 && *p2; p1++, p2++) {
        if (*p1 != *p2) return false;
    }
    if (*p1 || *p2) return false;
    else return true;
}

char* WordList::word_copy(char* word1) {
    char* word = new char[100];
    char* p1, * p2;
    for (p1 = word, p2 = word1; *p2; p1++, p2++) { *p1 = *p2; }
    *(p1) = *(p2);
    return word;
}

// ---------- Конструкторы ----------
WordList::~WordList() {
    Node* p = head;
    head = nullptr;
    while (p) {
        delete[]p->word;
        p = p->link;
    }
};

void test_funcs() {
    WordList lst;

    lst.push("word1");
    lst.push("word2");
    lst.push("word3");

    cout << lst[0] << endl;
    cout << lst[1] << endl;
    cout << lst[2] << endl;
    cout << lst[3] << endl;

    cout << lst.pop(2) << endl;
    cout << lst.pop() << endl;
    cout << lst.pop(4) << endl;

    lst.clear();
}

void test_concole() {
    WordList lst;

    int n;
    cout << "Enter amount of words: "; cin >> n;
    cout << "Enter words:\n";

    for (int i = 0; i < n; i++) {
        char word[100];
        cin >> word;
        lst.push(word);
    }

    cout << "Your list now looks like this:\n";

    for (int i = 0; i < lst.len(); i++) {
        cout << lst[i] << endl;
    }

    char replace[100], replacement[100];

    cout << "Enter word to replace: "; cin >> replace;
    cout << "Enter word to place instead: "; cin >> replacement;

    lst.replace(replace, replacement);

    cout << "Your list now looks like this:\n";

    for (int i = 0; i < lst.len(); i++) {
        cout << lst[i] << endl;
    }
}

void test_file() {

    WordList lst;
    fstream inp("input.txt", ios::in);
    int n;
    cout << "Amount of words: "; inp >> n; cout << n << endl;
    cout << "Words before:\n";

    for (int i = 0; i < n; i++) {
        char word[100];
        inp >> word; cout << word << endl;
        lst.push(word);
    }

    char replace[100], replacement[100];

    cout << "Word to replace: "; inp >> replace; cout << replace << endl;
    cout << "Word to place instead: "; inp >> replacement; cout << replacement << endl;

    lst.replace(replace, replacement);

    cout << "Your list now looks like this:\n";

    for (int i = 0; i < lst.len(); i++) {
        cout << lst[i] << endl;
    }
}

int main() {

    test_funcs();
    // test_concole();
    // test_file();

    return 0;
}