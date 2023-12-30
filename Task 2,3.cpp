#include <iostream>
#include <string>
using namespace std;

class Inventory {
private:
    int number;
    string type;
    string name;

public:
    // Конструктор с параметрами
    Inventory(int num, string t, string n) : number(num), type(t), name(n) { Inventory }

    // Конструктор копирования
    Inventory(const Inventory& other) : number(other.number), type(other.type), name(other.name) { Inventory }

    // Конструктор перемещения
    Inventory(string n) : number(0), type(""), name(n) { Inventory }

    // Деструктор
    ~Inventory() { Inventory }

    // Метод выводит всю информацию
    void printInfo() {
        cout << "Number: " << number << endl;
        cout << "Type: " << type << endl;
        cout << "Name: " << name << endl;
    }

    // Геттер для получения значения поля name
    string getName() const {
        return name;
    }

    // Геттер для получения значения поля type
    string getType() const {
        return type;
    }
};

// Функция, которая выводит данные объектов с совпадающим типом
void printInventory(string type, Inventory* inventory, int size) {
    for (int i = 0; i < size; i++) {
        if (inventory[i].getType() == type) {
            inventory[i].printInfo();
        }
    }
}

// Функция для поиска объекта по имени и вывода информации о нем
void findAndPrintObject(string name, Inventory* inventory, int size) {
    for (int i = 0; i < size; i++) {
        if (inventory[i].getName() == name) {
            inventory[i].printInfo();
            return;  
        }
    }
    cout << "Объект с именем '" << name << "' не найден." << endl;
}

int main() {
    // Создаем объекты класса Inventory
    Inventory obj1(1, "Type1", "Item1");
    Inventory obj2(2, "Type2", "Item2");
    Inventory obj3(3, "Type3", "Item3");

    obj1.printInfo();
    obj2.printInfo();
    obj3.printInfo();

    // Создаем массив объектов класса Inventory
    Inventory inventoryArray[3] = { obj1, obj2, obj3 };

    // Выводим данные объектов с совпадающим типом
    printInventory("Type2", inventoryArray, 3);

    string inputName;
    cout << "Введите имя объекта для поиска: ";
    cin >> inputName;

    findAndPrintObject(inputName, inventoryArray, 3);

    return 0;
}
