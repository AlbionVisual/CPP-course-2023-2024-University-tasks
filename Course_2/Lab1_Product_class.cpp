#include <iostream>

using namespace std;

const int MAX_PRODUCTS = 100; // Максимальное количество товаров

// Класс Product
class Product {
private:
    char name[50];          // Наименование
    char manufacturer[50];  // Производитель
    double price;           // Цена
    int shelfLife;          // Срок хранения (в днях)
    int quantity;           // Количество

public:
    // Конструктор по умолчанию
    Product() {
        price = 0.0;
        shelfLife = 0;
        quantity = 0;
        name[0] = '\0'; // создаём пустую строку
        manufacturer[0] = '\0';
    }

    // Методы set
    void setName(const char* name) {
        int i = 0;
        while (name[i] != '\0' && i < 49) {
            this->name[i] = name[i];
            i++;
        }
        this->name[i] = '\0';
    }

    void setManufacturer(const char* manufacturer) {
        int i = 0;
        while (manufacturer[i] != '\0' && i < 49) {
            this->manufacturer[i] = manufacturer[i]; // копирование строки с новым именем в поле name
            i++;
        }
        this->manufacturer[i] = '\0';
    }

    void setPrice(double newprice) { price = newprice; } // Установка новой цены (newprice) в поле price
    void setShelfLife(int newshelfLife) { shelfLife = newshelfLife; }
    void setQuantity(int newquantity) { quantity = newquantity; }

    // Методы get
    const char* getName() { return name; }
    const char* getManufacturer() { return manufacturer; }
    double getPrice() { return price; }
    int getShelfLife() { return shelfLife; }
    int getQuantity() { return quantity; }

    // Метод show для вывода информации о товаре
    void show() {
        cout << "Наименование: " << name << endl;
        cout << "Производитель: " << manufacturer << endl;
        cout << "Цена: " << price << endl;
        cout << "Срок хранения: " << shelfLife << " дней" << endl;
        cout << "Количество: " << quantity << endl;
    }
};

// Функция для вывода списка товаров по заданному наименованию
void listByName(Product products[], int n, const char* name) {
    cout << "Список товаров с наименованием \"" << name << "\":" << endl;
    for (int i = 0; i < n; i=i+1) {
        if (strcmp(products[i].getName(), name) == 0) {
            products[i].show();
            cout << endl;
        }
    }
}

// Функция для вывода списка товаров по наименованию с ценой не выше указанной
void listByNameAndPrice(Product products[], int n, const char* name, double maxPrice) {
    cout << "Список товаров с наименованием \"" << name << "\", цена которых не превышает " << maxPrice << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].getName(), name) == 0 && products[i].getPrice() <= maxPrice) {
            products[i].show();
            cout << endl;
        }
    }
}

// Функция для вывода списка товаров с сроком хранения больше указанного
void listByShelfLife(Product products[], int n, int minShelfLife) {
    cout << "Список товаров с сроком хранения больше " << minShelfLife << " дней:" << endl;
    for (int i = 0; i < n; i++) {
        if (products[i].getShelfLife() > minShelfLife) {
            products[i].show();
            cout << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    int n; // Количество товаров
    cout << "Введите количество товаров: ";
    cin >> n;

    if (n > MAX_PRODUCTS) {
        cout << "Ошибка: Максимальное количество товаров: " << MAX_PRODUCTS << endl;
        return 1;
    }

    Product products[MAX_PRODUCTS]; // Массив объектов класса Product

    // Ввод данных для каждого товара
    for (int i = 0; i < n; i++) {
        char name[50], manufacturer[50];
        double price;
        int shelfLife, quantity;

        cout << "Введите информацию для товара " << i + 1 << endl;
        cout << "Наименование: ";
        cin >> name;
        cout << "Производитель: ";
        cin >> manufacturer;
        cout << "Цена: ";
        cin >> price;
        cout << "Срок хранения (в днях): ";
        cin >> shelfLife;
        cout << "Количество: ";
        cin >> quantity;
        products[i].setName(name);
        products[i].setManufacturer(manufacturer);
        products[i].setPrice(price);
        products[i].setShelfLife(shelfLife);
        products[i].setQuantity(quantity);
    }

    // Вывод списка товаров по наименованию
    char searchName[50];
    cout << "Введите наименование для поиска: ";
    cin >> searchName;
    listByName(products, n, searchName);

    // Вывод списка товаров по наименованию и цене
    double maxPrice;
    cout << "Введите максимальную цену для поиска товаров: ";
    cin >> maxPrice;
    listByNameAndPrice(products, n, searchName, maxPrice);

    // Вывод списка товаров с сроком хранения больше указанного
    int minShelfLife;
    cout << "Введите минимальный срок хранения для поиска товаров: ";
    cin >> minShelfLife;
    listByShelfLife(products, n, minShelfLife);

    return 0;
}