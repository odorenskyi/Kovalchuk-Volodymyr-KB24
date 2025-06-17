#ifndef MODULSE_KOVALCHUK_H
#define MODULSE_KOVALCHUK_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

class ClassLab12_Kovalchuk {
private:
    double a; // велика піввісь еліпса
    double b; // мала піввісь еліпса

    // Допоміжна функція для правильного відображення тексту
    void printText(const char* text) const {
        cout << text;
    }

public:
    // Конструктор за замовчуванням
    ClassLab12_Kovalchuk() : a(5.0), b(3.0) {
        printText("Створено еліптичний стіл за замовчуванням (a=");
        cout << a << ", b=" << b << ")" << endl;
    }

    // Конструктор з параметрами
    ClassLab12_Kovalchuk(double a_val, double b_val) : a(a_val), b(b_val) {
        printText("Створено еліптичний стіл з параметрами (a=");
        cout << a << ", b=" << b << ")" << endl;
    }

    // Деструктор
    ~ClassLab12_Kovalchuk() {
        printText("Знищено об'єкт еліптичного столу");
        cout << endl;
    }

    // Методи для отримання значень атрибутів
    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    // Методи для встановлення значень атрибутів
    void setA(double new_a) {
        if (new_a > 0) {
            a = new_a;
            printText("Встановлено нове значення a = ");
            cout << a << endl;
        } else {
            printText("Помилка: значення a повинно бути більше 0");
            cout << endl;
        }
    }

    void setB(double new_b) {
        if (new_b > 0) {
            b = new_b;
            printText("Встановлено нове значення b = ");
            cout << b << endl;
        } else {
            printText("Помилка: значення b повинно бути більше 0");
            cout << endl;
        }
    }

    // Обчислення площі еліпса
    double calculateArea() const {
        return M_PI * a * b;
    }

    // Відображення інформації про стіл
    void displayInfo() const {
        cout << fixed << setprecision(2);
        printText("=== Інформація про еліптичний стіл ===");
        cout << endl;
        printText("Велика піввісь (a): ");
        cout << a << " од." << endl;
        printText("Мала піввісь (b):   ");
        cout << b << " од." << endl;
        printText("Площа поверхні:     ");
        cout << calculateArea() << " кв.од." << endl;
        printText("=====================================");
        cout << endl;
    }

    // Порівняння столів за площею
    bool isLargerThan(const ClassLab12_Kovalchuk& other) const {
        return this->calculateArea() > other.calculateArea();
    }

    // Перевантаження оператора виводу
    friend ostream& operator<<(ostream& os, const ClassLab12_Kovalchuk& table) {
        os << "Еліптичний стіл [a=" << table.a << ", b=" << table.b
           << ", площа=" << table.calculateArea() << "]";
        return os;
    }
};

#endif // MODULSE_KOVALCHUK_H
