// Laba_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "smartphones.h"
#include "PhonesList.h"
#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "rus");

    PhonesList list;

    cout << "Выполнил студент группы ИПсп-121:\n" << endl;
    cout << "Аверкин Сергей Максимович" << endl;

    cout << "" << endl;

    cout << "Список смартфонов:\n" << endl;
    cout << "- iPhone 12" << endl;
    cout << "- Samsung Galaxy S21" << endl;
    cout << "- Pixel 5" << endl;
    cout << "- Honor S10" << endl;
    cout << "- Redmi Nova X9" << endl;

    cout << " " << endl;

    // Добавление элементов в список
    list.addToPosition({ "Apple", "iPhone 12", 38000.00, 6.1 }, 0);
    list.addToPosition({ "Samsung", "Galaxy S21", 25000.00, 6.2 }, 1);
    list.addToPosition({ "Google", "Pixel 5", 12000.00, 5.0 }, 2);
    list.addToPosition({ "Huawei", "Honor S10", 15000.00, 6.1 }, 3);
    list.addToPosition({ "Xiaomi", "Redmi Nova X9", 22000.00, 7.9 }, 4);

    

    // Удаление элемента
    try {
        list.removeFromPosition(1);
    }
    catch (const std::out_of_range& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    // Получение значения элемента по номеру позиции
    try {
        Smartphone phone = list.getValueAtPosition(3);
        cout << "Смартфон под номером 3: " << phone.brand << " " << phone.model << endl;
    }
    catch (const std::out_of_range& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    // Проверка наличия в списке смартфона заданной марки
    pair<int, int> positions = list.findBrand("Apple");
    if (positions.first != -1) {
        cout << "Найденные смартфоны бренда Apple в позициях:" << positions.first << " и " << positions.second << endl;
    }
    else {
        cout << "Смартфоны бренда Apple не найдены в списке!" << endl;
    }

    // Получение описаний всех смартфонов с указанной диагональю экрана
    vector<Smartphone> smartphones = list.getSmartphonesWithScreenSize(6.1);
    cout << "Смартфоны с размером диагонали экрана 6.1:\n";
    for (const auto& phone : smartphones) {
        cout << phone.brand << " " << phone.model << endl;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
