/* В следующих заданиях требуется создать базовый класс (как вари-ант абстрактный
базовый класс) и определить общие методы show(), get(), set() и другие,
специфические для данного класса. Создать производные классы, в которые добавить
свойства и методы.

Часть методов переопределить. Создать массив объектов базового класса и заполнить
объектами производных классов. Объекты произ-водных классов идентифицировать
конструктором по имени или иден-тификационному номеру.

Вызвать метод show() базового класса и просмотреть массив объ-ектов.

Использовать объекты для моделирования реальных ситуаций.

8. Создать абстрактный класс «Работник фирмы» и производные классы «Менеджер»,
«Администратор», «Программист». */
// Абстрактный означает отвлечённый от конкретных деталей, представляющий собой
// обобщенное понятие или идею

#include <iostream>

using namespace std;

class Worker {                                                  // Abstract class
protected:
    char name[20];
public:

    Worker() {};
    Worker(char* new_name) { strncpy(name, new_name, 20); }     // Constructors

    virtual void show() = 0;                                    // Virtual methods
    virtual void set(Worker** friends, int amount) = 0;

    char* get() { return name; };

};

class Manager : public Worker {                                 // Manager class
    int leaderboard_pos = 0;
    Worker** coworkers = nullptr;
    int amount_of_coworkers = 0;
public:
    // Constructors
    Manager(char* new_name, int leaderboard) :Worker(new_name) {
        leaderboard_pos = leaderboard;
    }

    Manager(char* new_name, Worker** list_of_subworkers, int n, int leaderboard = 1) : Worker(new_name) {
        coworkers = list_of_subworkers;
        amount_of_coworkers = n;
        leaderboard_pos = leaderboard;
    }

    void show() override {                                      // Overriden methods
        cout << "Manager " << name << " has posistion " << leaderboard_pos << " in leaderboard" << endl << "Coworkers:" << endl;
        // for (int i = 0; i < amount_of_coworkers; i++) {
        //     cout << "\t"; coworkers[i]->show();
        // }
    }

    void set(Worker** friends, int amount) override {
        coworkers = friends;
        amount_of_coworkers = amount;
    }

};

class Admin : public Worker {                                   // Admin class
    Worker** subordinates;
    int amount_of_subordinates = 0;
public:

    Admin(char* new_name) :Worker(new_name) {};                 // Constructors

    Admin(char* new_name, Worker** list_of_subworkers, int n) : Worker(new_name) {
        subordinates = list_of_subworkers;
        amount_of_subordinates = n;
    }

    void show() override {                                      // Overriden methods
        cout << "Administrator " << name << endl << "Subworkers:" << endl;
        // for (int i = 0; i < amount_of_subordinates; i++) {
        //     subordinates[i]->show();
        // }
    }

    void set(Worker** friends, int amount) override {
        subordinates = friends;
        amount_of_subordinates = amount;
    }
};

class Programmer : public Worker {                              // Programmer class
    int leadership = 0;
public:
    // Constructor
    Programmer(char* new_name, int leadership_amount = -1) : Worker(new_name) {
        if (leadership_amount != -1) { leadership = leadership_amount; }
    }

    void show() override {                                      // Overriden methods
        cout << "Promgrammer " << name << " has " << leadership << " points of leadership abilities" << endl;
    }

    // NO FRIENDS, UA-HA-HA
    void set(Worker** friends, int amount) override {};         // Required for dev purposes only

};

int main() {

    Worker* office_workers[7];
    office_workers[0] = new Admin("Andrew");
    office_workers[1] = new Manager("Ann", 1);
    office_workers[2] = new Manager("Richard", 2);
    office_workers[3] = new Programmer("Phill", 7);
    office_workers[4] = new Programmer("Lazy", 2);
    office_workers[5] = new Programmer("Alice", 5);
    office_workers[6] = new Programmer("Man", 1);

    // Worker w1 = Worker("242");

    // office_workers[0]->set(&office_workers[1], 2);
    // office_workers[1]->set(&office_workers[3], 2);
    // office_workers[2]->set(&office_workers[5], 2);

    for (int i = 0; i < 7; i++) office_workers[i]->show();


    cout << endl << office_workers[0]->get() << endl;

    return 0;
}