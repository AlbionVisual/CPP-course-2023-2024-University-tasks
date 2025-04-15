/* При выполнении приводимых ниже заданий можно использовать классы, разработанные в
лабораторных работах № 1–3. Осуществлять контроль состояния потоков. В случае возникновения
ошибок потоков генерировать и обрабатывать исключительные ситуации. Для соответствующих
классов перегрузить операции вставки в поток и извлечения из потока. При динамическом
выделении памяти предусмотреть обработку исключения, возникающего при нехватке памяти.

8. Для класса WordList (лаб. работа № 3) предусмотреть ввод данных из файла. Результат
вывести в файл. */

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
    friend ostream& operator<< (ostream& stream, const WordList& stud); // Операторы потоков должны возвращать ссылку на поток
    friend istream& operator>> (istream& stream, WordList& stud);

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
        return head->word;
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
            return head->word;
        }
        p = p->link;
    }
    return p->word;
}

ostream& operator<< (ostream& stream, const WordList& words) { // Операторы потоков должны возвращать ссылку на поток
    stream << "Amount: " << words.amount << endl;
    Node* p = words.head;
    int i = 1;
    while (p) {
        stream << i << ": " << p->word << endl;
        p = p->link;
        i++;
    }
    return stream;
}

istream& operator>> (istream& stream, WordList& words) {
    int n;
    stream >> n;

    for (int i = 0; i < n; i++) {
        char word[100];
        stream >> word;
        words.push(word);
    }
    return stream;
}

// ---------- Другие методы ------------------
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

// ---------- Деструкторы ----------
WordList::~WordList() {
    Node* p = head;
    head = nullptr;
    while (p) {
        delete[]p->word;
        p = p->link;
    }
};

// ---------- Main -----------------
int main() {

    try {

        WordList lst;

        fstream fin("inpugt.txt", ios::in);
        if (!fin) throw 3;

        fin >> lst;

        cout << "Your list:\n";
        cout << lst;

        char replace[100], replacement[100];

        cout << "Word to replace: "; fin >> replace; cout << replace << endl;
        cout << "Enter word to place instead: "; fin >> replacement; cout << replacement << endl;
        fin.close();

        lst.replace(replace, replacement);

        fstream fout("output.txt", ios::out);

        fout << lst;

    }
    catch (int x) {
        cout << "Error number: " << x;
        return 1;
    }
    catch (...) {
        cout << "Other error";
        return 1;
    }

    cout << "Answer written in file successfully!\n";

    return 0;
}