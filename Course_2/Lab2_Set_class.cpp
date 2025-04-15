#include <iostream>
#define settype char

using namespace std;

class Set {
private:
    settype* data;                              // Массив для хранения элементов множества
    int size;                                   // Мощность множества
    int capacity;                               // Максимальный размер множества

public:
    // Конструктор по умолчанию
    Set() { data = nullptr; size = 0; capacity = 0; }

    // Конструктор с заданной мощностью
    Set(int n) { size = 0; capacity = n; data = new settype[capacity]; }

    // Конструктор копирования
    Set(const Set& other);

    // Деструктор
    ~Set() { delete[] data; }

    // Метод для добавления элемента в множество
    void add(settype element);

    // Метод для проверки принадлежности элемента множеству
    bool contains(settype element) const;       // const указывает, что метод не меняет объекта, для которого он был вызван

    // Перегрузка оператора сложения (объединение множеств)
    Set operator+(const Set& other) const;

    // Перегрузка оператора вычитания (разность множеств)
    Set operator-(const Set& other) const;

    // Перегрузка оператора умножения (пересечение множеств)
    Set operator*(const Set& other) const;

    // Перегрузка оператора индексирования
    settype operator[](int index) const;

    // Перегрузка оператора присваивания
    Set& operator=(const Set& other);

    // Метод для вывода множества на экран
    void print() const;
};

// Конструкторы
Set::Set(const Set& other) {
    size = other.size;
    capacity = other.capacity;
    data = new settype[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Методы
void Set::add(settype element) {
    if (size < capacity) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (data[i] == element) {
                found = true;
                break;
            }
        }
        if (!found) {
            data[size++] = element;
        }
    }
}

bool Set::contains(settype element) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == element) {
            return true;
        }
    }
    return false;
}

void Set::print() const {
    cout << "{";
    for (int i = 0; i < size; ++i) {
        cout << data[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

// Перегрузка операторов
Set Set::operator+(const Set& other) const {
    Set result(size + other.size);
    for (int i = 0; i < size; i++) {
        result.add(data[i]);
    }
    for (int i = 0; i < other.size; i++) {
        result.add(other.data[i]);
    }
    return result;
}

Set Set::operator-(const Set& other) const {
    Set result(size);
    for (int i = 0; i < size; ++i) {
        if (!other.contains(data[i])) {
            result.add(data[i]);
        }
    }
    return result;
}

Set Set::operator*(const Set& other) const {
    Set result(size);
    for (int i = 0; i < size; ++i) {
        if (other.contains(data[i])) {
            result.add(data[i]);
        }
    }
    return result;
}

settype Set::operator[](int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return 0; // Возвращаем 0, если индекс некорректный
}

Set& Set::operator=(const Set& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new settype[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Функция для построения нового множества из элементов, входящих только в одно из заданных множеств
Set buildSymmetricDifference(const Set& set1, const Set& set2) {
    return (set1 + set2) - (set1 * set2);
}

int main() {
    // Пример использования класса Set
    Set set1(5);
    set1.add('1');
    set1.add('2');
    set1.add('3');

    Set set2(5);
    set2.add('2');
    set2.add('3');
    set2.add('4');

    cout << "Set1: ";
    set1.print();
    cout << "Set2: ";
    set2.print();

    Set unionSet = set1 + set2;
    cout << "Union: ";
    unionSet.print();

    Set intersectionSet = set1 * set2;
    cout << "Intersection: ";
    intersectionSet.print();

    Set differenceSet = set1 - set2;
    cout << "Difference (Set1 - Set2): ";
    differenceSet.print();



    Set set3(5);
    set2.add('3');
    set2.add('4');
    set2.add('5');

    const int N = 3;
    // Set* sets = new Set[N]{ set1, set2, set3 };
    Set sets[N] = { set1, set2, set3 };
    cout << "Symmetric Differences:\n";
    for (int i = 0; i < N - 1; i++) {
        Set symmetricDifferenceSet = buildSymmetricDifference(sets[i], sets[i + 1]);
        symmetricDifferenceSet.print();
    }

    return 0;
}