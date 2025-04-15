/*  9. Создать шаблон класса Set (множество) мощности n (см. задачу № 9, лаб. работа № 2 )
или создать шаблон класса для работы с одно-связным списком. Применить шаблон класса для
решения задачи № 9 (лаб. работа № 3):
Проверить, содержатся ли элементы списка List1 в списке List2 в указанном списком List1
порядке. */

#include <iostream>

using namespace std;

template<class settype>
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
    Set(const Set<settype>& other);

    // Деструктор
    ~Set() { delete[] data; }

    // Метод для добавления элемента в множество
    void add(settype element);

    // Метод для проверки принадлежности элемента множеству
    bool contains(settype element) const;       // const указывает, что метод не меняет объекта, для которого он был вызван

    // Узнать кол-во элементов мн-ва
    int len() { return size; };

    // Перегрузка оператора сложения (объединение множеств)
    Set operator+(const Set<settype>& other) const;

    // Перегрузка оператора вычитания (разность множеств)
    Set operator-(const Set<settype>& other) const;

    // Перегрузка оператора умножения (пересечение множеств)
    Set operator*(const Set<settype>& other) const;

    // Перегрузка оператора индексирования
    settype operator[](int index) const;

    // Перегрузка оператора присваивания
    Set& operator=(const Set<settype>& other);

    // Метод для вывода множества на экран
    void print() const;
};

// Конструкторы
template<class settype>
Set<settype>::Set(const Set<settype>& other) {
    size = other.size;
    capacity = other.capacity;
    data = new settype[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Методы
template<class settype>
void Set<settype>::add(settype element) {
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

template<class settype>
bool Set<settype>::contains(settype element) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == element) {
            return true;
        }
    }
    return false;
}

template<class settype>
void Set<settype>::print() const {
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
template<class settype>
Set<settype> Set<settype>::operator+(const Set<settype>& other) const {
    Set<settype> result(size + other.size);
    for (int i = 0; i < size; i++) {
        result.add(data[i]);
    }
    for (int i = 0; i < other.size; i++) {
        result.add(other.data[i]);
    }
    return result;
}

template<class settype>
Set<settype> Set<settype>::operator-(const Set<settype>& other) const {
    Set result(size);
    for (int i = 0; i < size; ++i) {
        if (!other.contains(data[i])) {
            result.add(data[i]);
        }
    }
    return result;
}

template<class settype>
Set<settype> Set<settype>::operator*(const Set<settype>& other) const {
    Set result(size);
    for (int i = 0; i < size; ++i) {
        if (other.contains(data[i])) {
            result.add(data[i]);
        }
    }
    return result;
}

template<class settype>
settype Set<settype>::operator[](int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return 0; // Возвращаем 0, если индекс некорректный
}

template<class settype>
Set<settype>& Set<settype>::operator=(const Set<settype>& other) {
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
template<class settype>
Set<settype> buildSymmetricDifference(const Set<settype>& set1, const Set<settype>& set2) {
    return (set1 + set2) - (set1 * set2);
}

int main() {
    // Пример использования класса Set
    Set<int> set1(5);
    set1.add(1);
    set1.add(2);
    set1.add(3);

    Set<int> set2(5);
    set2.add(2);
    set2.add(3);
    set2.add(4);

    cout << "Set1: ";
    set1.print();
    cout << "Set2: ";
    set2.print();

    Set<int> intersectionSet = set1 * set2;
    cout << "Intersection: ";
    intersectionSet.print();

    cout << "Set1.len(): " << set1.len() << "; Intersection.len(): " << intersectionSet.len() << " => ";
    if (set1.len() == intersectionSet.len()) cout << "Second set contains first" << endl;
    else cout << "Second set does't contain first set" << endl;

    set2.add(1);

    cout << "Adding new element: 1 - in second set" << endl;
    intersectionSet = set1 * set2;
    cout << "Set1.len(): " << set1.len() << "; Intersection.len(): " << intersectionSet.len() << " => ";
    if (set1.len() == intersectionSet.len()) cout << "Second set contains first" << endl;
    else cout << "Second set does't contain first set";

    Set<char> set3(3);
    set3.add('a');
    set3.add('b');
    set3.add('c');

    cout << "Symbolic set: ";
    set3.print();

    return 0;
}