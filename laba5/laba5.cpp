#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class Car {
private:
    string name;        // Название модели
    string maker;       // Производитель
    string transmission; // Коробка передач
    string color;       // Цвет
    int year;           // Год выпуска
    double engineSize;  // Объём двигателя
    double price;       // Цена

public:
    // Конструктор
    Car() : maker(""), name(""), transmission(""), color(""), year(0), engineSize(0.0), price(0.0){}

    // Метод для ввода данных
    void dataInput() {
        cout << "Введите производителя: ";
        getline(cin, maker);
        cout << "Введите название модели: ";
        getline(cin, name);
        cout << "Введите тип коробки передач (AT/MT): ";
        getline(cin, transmission);
        cout << "Введите цвет: ";
        getline(cin, color);
        cout << "Введите год выпуска: ";
        cin >> year;
        cin.ignore();//Чистим буфер
        cout << "Введите объём двигателя: ";
        cin >> engineSize;
        cout << "Введите цену: ";
        cin >> price;
    }

    // Метод для вывода всех данных
    void dataOutput() const {
        setlocale(LC_ALL, "Rus");
        cout << string(35, '-') << endl;
        cout << "Производитель: " << maker << endl;
        cout << "Название модели: " << name << endl;
        cout << "Коробка передач: " << transmission << endl;
        cout << "Цвет: " << color << endl;
        cout << "Год выпуска: " << year << endl;
        cout << "Объём двигателя: " << engineSize << endl;
        cout << "Цена: " << price << endl;
    }

    // Функции для доступа к полям
    int getYear() const { return year; }
    double getPrice() const { return price; }
    string getTransmission() const { return transmission; }

    // Сравнение для сортировки
    static bool sortByYear(const Car& a, const Car& b) {
        return a.getYear() < b.getYear();
    }

    static bool sortByPrice(const Car& a, const Car& b) {
        return a.getPrice() < b.getPrice();
    }

    static bool sortByTransmission(const Car& a, const Car& b) {
        return a.getTransmission() < b.getTransmission();
    }

    // Метод для редактирования информации о автомобиле
    void editInfo() {
        cout << "Редактирование информации о автомобиле:" << endl;
        cout << "Введите новую марку автомобиля (текущая: " << maker << "): ";
        getline(cin, maker);
        cout << "Введите новую модель автомобиля (текущая: " << name << "): ";
        getline(cin, maker);
        cout << "Введите новый тип коробки передач (текущий: " << transmission << "): ";
        getline(cin, transmission);
        cout << "Введите новый цвет (текущий: " << color << "): ";
        getline(cin, color);
        cout << "Введите новый год выпуска (текущий: " << year << "): ";
        cin >> year;
        cout << "Введите новый мотор (текущий: " << engineSize << "): ";
        cin >> engineSize;
        cout << "Введите новую цену (текущая: " << price << "): ";
        cin >> price;
        // cin.ignore();  // Чистим буфер перед следующим вводом
        
    }
};

void displayMenu() {
    cout << "KorAuto51" << endl;
    cout << "Меню:" << endl;
    cout << "1. Добавить автомобиль" << endl;
    cout << "2. Просмотреть каталог автомобилей" << endl;
    cout << "3. Сортировать автомобили" << endl;
    cout << "4. Редактировать автомобиль" << endl;
    cout << "5. Справка по работе" << endl;
    cout << "6. Выход" << endl;
    cout << "Выберите опцию: ";
}

int main() {

    setlocale(LC_ALL, "Rus");

    vector<Car> cars;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();  // Чистим буфер перед следующими вводами

        switch (choice) {
        case 1: {
            Car newCar;
            newCar.dataInput();
            cars.push_back(newCar);
            cout << "Автомобиль добавлен!" << endl;
            break;
        }
        case 2: {
            cout << "Каталог автомобилей:" << endl;
            for (const auto& car : cars) {
                car.dataOutput();
            }
            break;
        }
        case 3: {
            int sortChoice;
            cout << "Выберите сортировку по:" << endl;
            cout << "1. Году выпуска" << endl;
            cout << "2. Цене" << endl;
            cout << "3. Коробке передач" << endl;
            cout << "Выберите опцию: ";
            cin >> sortChoice;

            switch (sortChoice) {
            case 1:
                sort(cars.begin(), cars.end(), Car::sortByYear);
                cout << "Сортировка по году выпуска завершена." << endl;
                break;
            case 2:
                sort(cars.begin(), cars.end(), Car::sortByPrice);
                cout << "Сортировка по цене завершена." << endl;
                break;
            case 3:
                sort(cars.begin(), cars.end(), Car::sortByTransmission);
                cout << "Сортировка по коробке передач завершена." << endl;
                break;
            default:
                cout << "Некорректный выбор." << endl;
            }
            break;
        }
        case 4: {
            if (cars.empty()) {
                cout << "Нет автомобилей для редактирования." << endl;
                break;
            }

            cout << "Выберите номер автомобиля для редактирования (1-" << cars.size() << "): ";
            int editIndex;
            cin >> editIndex;
            cin.ignore();  // Чистим буфер перед следующими вводами

            if (editIndex < 1 || editIndex > cars.size()) {
                cout << "Некорректный номер автомобиля." << endl;
            }
            else {
                cars[editIndex - 1].editInfo();
                cout << "Информация об автомобиле обновлена!" << endl;
            }
            break;
        }
        case 5:
            cout << "Справка по работе" << endl;
            cout << "САМОЕ ГЛАВНОЕ, пишем все на English!!!" << endl;
            break;
        case 6:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте еще раз." << endl;
        }

        cout << endl;

    } while (choice != 6);

    return 0;
}