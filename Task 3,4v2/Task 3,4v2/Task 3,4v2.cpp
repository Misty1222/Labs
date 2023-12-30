#include <iostream>
#include <locale>

using namespace std;
// Класс `Parent`
class Parent
{
public:
   virtual void printName(void) { cout << "Parent" << endl; }
    static string getMsg2() { return msg2; }

private:
    // Приватный член `msg2`
    static string msg2;
protected:
    // Защищенный член `msg3`
    string msg3 = "C";
};

string Parent::msg2 = "B";

// Класс `Child`, от класса `Parent`
class Child : public Parent {
public:
    void printName(void) { cout << "Child" << endl; }
    void printOnlyProtected()
    {
        cout << getMsg2() << endl;
    }
};

// Класс для инвентаризации
class Inventorization
{
public:
    string name;
    int price;
};

// Класс стола
class Table : public Inventorization {
public:
    int height;
    int width;
};

// Класс стула
class Chair : public Inventorization {
public:
    int height;
    int width;
    int depth;
};

// Класс мыши
class Mouse : public Inventorization {
public:
    int weight;
    int number_of_buttons;
};

// Класс компьютера
class Computer : public Inventorization {
public:
    int processor_speed;
    int memory_size;
    int storage_size;
};

// Класс монитора
class Monitor : public Inventorization {
public:
    int screen_size;
    int resolution;
};

int main(void) {
    Parent p;
    Child c;

    Parent* other = &c;

    p.printName();
    c.printName();
    other->printName();

    cout << Parent::getMsg2() << endl;

    return (0);
}

// Основная функция
int main1()

{
  // setlocale(LC_ALL, "Russiаn");
    std::locale cp1251_locale("ru_RU");
    std::locale::global(cp1251_locale);
    // Создаем экземпляр класса `Child`
    Child child;

    // Вызываем метод `printOnlyProtected()`
    child.printOnlyProtected();

    // Создание экземпляра класса стола
    Table table;
    table.name = "Стол";
    table.price = 10000;
    table.height = 75;
    table.width = 150;

    // Создание экземпляра класса стула
    Chair chair;
    chair.name = "Стул";
    chair.price = 5000;
    chair.height = 90;
    chair.width = 50;
    chair.depth = 50;

    // Создание экземпляра класса мыши
    Mouse mouse;
    mouse.name = "Мышь";
    mouse.price = 1000;
    mouse.weight = 100;
    mouse.number_of_buttons = 5;

    // Создание экземпляра класса компьютера
    Computer computer;
    computer.name = "Компьютер";
    computer.price = 100000;
    computer.processor_speed = 3.5;
    computer.memory_size = 16;
    computer.storage_size = 1000;

    // Создание экземпляра класса монитора
    Monitor monitor;
    monitor.name = "Монитор";
    monitor.price = 25000;
    monitor.screen_size = 27;
    monitor.resolution = 2560 * 1440;

    // Вывод данных о каждом объекте инвентаризации
    cout << "Стол: " << table.name << ", цена: " << table.price << ", высота: " << table.height << ", ширина: " << table.width << endl;
    cout << "Стул: " << chair.name << ", цена: " << chair.price << ", высота: " << chair.height << ", ширина: " << chair.width << ", глубина: " << chair.depth << endl;
    cout << "Мышь: " << mouse.name << ", цена: " << mouse.price << ", вес: " << mouse.weight << ", количество кнопок: " << mouse.number_of_buttons << endl;
    cout << "Компьютер: " << computer.name << ", цена: " << computer.price << ", скорость процессора: " << computer.processor_speed << ", объем памяти: " << computer.memory_size << ", объем накопителя: " << computer.storage_size << endl;
    cout << "Монитор: " << monitor.name << ", цена: " << monitor.price << ", размер экрана: " << monitor.screen_size << ", разрешение: " << monitor.resolution << endl;

    return 0;
}
