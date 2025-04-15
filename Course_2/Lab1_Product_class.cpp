#include <iostream>

using namespace std;

const int MAX_PRODUCTS = 100; // ������������ ���������� �������

// ����� Product
class Product {
private:
    char name[50];          // ������������
    char manufacturer[50];  // �������������
    double price;           // ����
    int shelfLife;          // ���� �������� (� ����)
    int quantity;           // ����������

public:
    // ����������� �� ���������
    Product() {
        price = 0.0;
        shelfLife = 0;
        quantity = 0;
        name[0] = '\0'; // ������ ������ ������
        manufacturer[0] = '\0';
    }

    // ������ set
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
            this->manufacturer[i] = manufacturer[i]; // ����������� ������ � ����� ������ � ���� name
            i++;
        }
        this->manufacturer[i] = '\0';
    }

    void setPrice(double newprice) { price = newprice; } // ��������� ����� ���� (newprice) � ���� price
    void setShelfLife(int newshelfLife) { shelfLife = newshelfLife; }
    void setQuantity(int newquantity) { quantity = newquantity; }

    // ������ get
    const char* getName() { return name; }
    const char* getManufacturer() { return manufacturer; }
    double getPrice() { return price; }
    int getShelfLife() { return shelfLife; }
    int getQuantity() { return quantity; }

    // ����� show ��� ������ ���������� � ������
    void show() {
        cout << "������������: " << name << endl;
        cout << "�������������: " << manufacturer << endl;
        cout << "����: " << price << endl;
        cout << "���� ��������: " << shelfLife << " ����" << endl;
        cout << "����������: " << quantity << endl;
    }
};

// ������� ��� ������ ������ ������� �� ��������� ������������
void listByName(Product products[], int n, const char* name) {
    cout << "������ ������� � ������������� \"" << name << "\":" << endl;
    for (int i = 0; i < n; i=i+1) {
        if (strcmp(products[i].getName(), name) == 0) {
            products[i].show();
            cout << endl;
        }
    }
}

// ������� ��� ������ ������ ������� �� ������������ � ����� �� ���� ���������
void listByNameAndPrice(Product products[], int n, const char* name, double maxPrice) {
    cout << "������ ������� � ������������� \"" << name << "\", ���� ������� �� ��������� " << maxPrice << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].getName(), name) == 0 && products[i].getPrice() <= maxPrice) {
            products[i].show();
            cout << endl;
        }
    }
}

// ������� ��� ������ ������ ������� � ������ �������� ������ ����������
void listByShelfLife(Product products[], int n, int minShelfLife) {
    cout << "������ ������� � ������ �������� ������ " << minShelfLife << " ����:" << endl;
    for (int i = 0; i < n; i++) {
        if (products[i].getShelfLife() > minShelfLife) {
            products[i].show();
            cout << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    int n; // ���������� �������
    cout << "������� ���������� �������: ";
    cin >> n;

    if (n > MAX_PRODUCTS) {
        cout << "������: ������������ ���������� �������: " << MAX_PRODUCTS << endl;
        return 1;
    }

    Product products[MAX_PRODUCTS]; // ������ �������� ������ Product

    // ���� ������ ��� ������� ������
    for (int i = 0; i < n; i++) {
        char name[50], manufacturer[50];
        double price;
        int shelfLife, quantity;

        cout << "������� ���������� ��� ������ " << i + 1 << endl;
        cout << "������������: ";
        cin >> name;
        cout << "�������������: ";
        cin >> manufacturer;
        cout << "����: ";
        cin >> price;
        cout << "���� �������� (� ����): ";
        cin >> shelfLife;
        cout << "����������: ";
        cin >> quantity;
        products[i].setName(name);
        products[i].setManufacturer(manufacturer);
        products[i].setPrice(price);
        products[i].setShelfLife(shelfLife);
        products[i].setQuantity(quantity);
    }

    // ����� ������ ������� �� ������������
    char searchName[50];
    cout << "������� ������������ ��� ������: ";
    cin >> searchName;
    listByName(products, n, searchName);

    // ����� ������ ������� �� ������������ � ����
    double maxPrice;
    cout << "������� ������������ ���� ��� ������ �������: ";
    cin >> maxPrice;
    listByNameAndPrice(products, n, searchName, maxPrice);

    // ����� ������ ������� � ������ �������� ������ ����������
    int minShelfLife;
    cout << "������� ����������� ���� �������� ��� ������ �������: ";
    cin >> minShelfLife;
    listByShelfLife(products, n, minShelfLife);

    return 0;
}