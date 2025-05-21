#include <iostream>
#include <windows.h>
#include <clocale>
#include "ModulseKovalchuk.h"

using namespace std;

int main() {
setlocale(LC_ALL, "ukr");
SetConsoleCP(65001);
SetConsoleOutputCP(65001);

string inputFile = "input.txt";
string outputFile = "output.txt";

int choice;
    cout << "==============================================" << endl;
    cout << "| Developer: Kovalchuk Volodymyr Olehovych  |" << endl;
    cout << "| Student of group KB-24                    |" << endl;
    cout << "| Educational institution: CNTU             |" << endl;
    cout << "==============================================" << endl;

      while (true) {
        cout << "\nОберіть дію:\n";
        cout << "1 - Аналіз пунктуації та авторська інформація (файл)\n";
        cout << "2 - Дозапис англійської абетки та дати у вхідний файл\n";
        cout << "3 - Обчислення виразу (x + y) * z та двійкове подання числа\n";
        cout << "0 - Вихід з програми\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nОпис: Перевірка вірша на пунктуаційні помилки та запис авторських даних у файл.\n";
                Task10_1(inputFile, outputFile);
                break;
        }
            case 2:{
                cout << "\nОпис: Дозапис англійської абетки та поточної дати й часу у вхідний файл.\n";
                Task10_2(inputFile);
                break;
            }
            case 3: {
                cout << "\nОпис: Обчислення виразу (x + y) * z і подання числа b у шістнадцятковій та двійковій формах.\n";
                double x, y, z;
                unsigned int b;
                cout << "Введіть x, y, z: ";
                cin >> x >> y >> z;
                cout << "Введіть натуральне число b: ";
                cin >> b;
                Task10_3(x, y, z, b, outputFile);
                break;
            }
            case 0:
                cout << "\nПрограма завершена.\n";
                return 0;
            default:
                cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }

    return 0;
}
