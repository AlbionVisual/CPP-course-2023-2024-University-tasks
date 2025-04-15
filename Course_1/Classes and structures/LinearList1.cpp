#include <iostream>
using namespace std;


struct Link {
    char* data;
    Link* next;
};

class LinkList {

private:
    Link* first;
    bool equal(char* p1, char* p2);

public:
    void additem(char* d);
    void display();
    void init(char* d);
    char* get(int id);
    int len();
    void deleteId(int id);
    int find(char* p);
    LinkList() { first = nullptr; }
    LinkList(char* d) { init(d); }
    ~LinkList() {
        while (first) {
            delete[] first->data;
            first = first->next;
        }
    }
};

LinkList parseStr(char*);
bool endWith(char* pstr, const char[] = "xyz");

int main() {

    char* pstr = new char[100] {"Somexyz sort ofxyz words or uselessxyz phrases"};
    LinkList words = parseStr(pstr);
    cout << pstr << endl;

    for (int i = 0; i < words.len(); i++)
        if (!endWith(words.get(i)))
            words.deleteId(i--);

    char* q = pstr;
    int i = 0;
    while (words.len()) {
        int j = 0;
        char* word = words.get(words.len() - 1);
        while (word[j]) *(q++) = word[j++];
        words.deleteId(words.len() - 1);
        *(q++) = ' ';
    }
    *q = '\0';

    cout << pstr << endl;
    
    return 0;
}

bool  LinkList::equal(char* p1, char* p2) {
    while (*p1 and *p2) {
        if (*p1 != *p2) return false;
        p1++;
        p2++;
    }
    if (*p1 != '\0' or *p2 != '\0') return false;
    return true;
}

void  LinkList::additem(char* d) {
    Link* newlink = new Link;
    newlink->data = d;
    newlink->next = first;
    first = newlink;
}
void  LinkList::display() {
    Link* current = first;
    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}
void  LinkList::init(char* d) {
    Link* newlink = new Link;
    newlink->data = d;
    newlink->next = nullptr;
    first = newlink;
}
int   LinkList::len() {
    int c = 0;
    Link* current = first;
    while (current) {
        c++;
        current = current->next;
    }
    return c++;
}
void  LinkList::deleteId(int id) {
    Link* current = first, *prev = nullptr;
    while (id) {
        id--;
        prev = current;
        current = current->next;
    }
    if (prev == nullptr) {
        first = current->next;
        delete[] current->data;
    }
    else {
        delete[] current->data;
        prev->next = current->next;
    }
}
int   LinkList::find(char* p) {
    Link* current = first;
    int id = 0;
    while (current) {
        if (equal(current->data, p)) return id;
        id++;
        current = current->next;
    }
    return -1;
}
char* LinkList::get(int id) {
    Link* current = first;
    while (id) {
        id--;
        current = current->next;
    }
    return current->data;
}

bool     contains(char p, char patt[]) {
    for (char* q = patt; *q; q++)
        if (*q == p) return true;
    return false;
}
LinkList parseStr(char* pstr) {
    char patt[] = " ,.;:";
    LinkList l;
    char* start = pstr;
    char* end = start;

    while (*start && *end) {
        while (contains(*start, patt) && *start) start += 1;
        end = start;

        while (!contains(*end, patt) && *end) end += 1;

        char* word = new char[end - start + 1];
        int id = 0;
        while (start != end) word[id++] = *(start++);
        word[id] = '\0';

        l.additem(word);
    }

    return l;
}
bool     endWith(char* pstr, const char pat[]) {
    int patlen = 0; for (const char* q = pat; *q; q++, patlen++);
    int strlen = 0; for (char* q = pstr; *q; q++, strlen++);

    if (patlen > strlen) return false;
    for (int i = strlen - patlen, j = 0; i < strlen; i++, j++)
        if (pstr[i] != pat[j]) return false;

    return true;
}

/*
#include <iostream>
using namespace std;

// 10000 1000 100 10 1 2 3 4 5 6

struct Link {
    int data;
    Link* next;
    Link* prev;
};

class LinkList {
    Link* first;
    Link* last;

public:
    void additem(int d);
    void display(bool = false);
    void init(int d);
    int get(int id, bool = false);
    int len();
    void deleteId(int id);
    int find(int p);
    LinkList() { first = nullptr; last = nullptr; }
    LinkList(int d) { init(d); }
    LinkList(int* arr, int n) {
        init(arr[0]);
        for (int i = 1; i < n; i++)
            additem(arr[i]);
    }
    ~LinkList() { 
        while (first) {
            Link* buff = first->next;
            delete first;
            first = buff;
        }
    }
};

int main() {

    int n; cout << "Enter n: "; cin >> n;
    int* row = new int[n * 2];
    cout << "Enter numbers: "; for (int i = 0; i < n * 2; i++) cin >> row[i];

    LinkList l(row, 2 * n);
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += l.get(i) * l.get(i, true);
    }

    cout << res << endl;

    return 0;
}

void  LinkList::additem(int d) {
    Link* newlink = new Link;
    newlink->data = d;
    newlink->next = first;
    first->prev = newlink;
    first = newlink;
}
void  LinkList::display(bool rev) {
    if (!rev) {
        Link* current = first;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    } else {
        Link* current = last;
        while (current) {
            cout << current->data << endl;
            current = current->prev;
        }
    }
}
void  LinkList::init(int d) {
    Link* newlink = new Link;
    newlink->data = d;
    newlink->next = nullptr;
    first = newlink;
    last = first;
}
int   LinkList::len() {
    int c = 0;
    Link* current = first;
    while (current) {
        c++;
        current = current->next;
    }
    return c++;
}
void  LinkList::deleteId(int id) {
    Link* current = first, * prev = nullptr;
    while (id) {
        id--;
        prev = current;
        current = current->next;
    }
    if (prev == nullptr) {
        Link* buff = first;
        first = current->next;
        delete buff->next;
        delete buff->prev;
    }
    else {
        Link* buff = first;
        first = current->next;
        buff->prev->next = first;
        delete buff->next;
        delete buff->prev;
    }
}
int   LinkList::find(int p) {
    Link* current = first;
    int id = 0;
    while (current) {
        if (current->data == p) return id;
        id++;
        current = current->next;
    }
    return -1;
}
int   LinkList::get(int id, bool rev) {
    Link* current;
    if (!rev) {
        current = first;
        while (id) {
            id--;
            current = current->next;
        }
    }
    else {
        current = last;
        while (id) {
            id--;
            current = current->prev;
        }
    }
    return current->data;
}
*/