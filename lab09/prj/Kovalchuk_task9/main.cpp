#include <iostream>
#include "ModulseKovalchuk.h"
#include "locale.h"

using namespace std;

int main()
{
     setlocale(LC_ALL, "ukr");
    cout << "==============================================" << endl;
    cout << "| Developer: Kovalchuk Volodymyr Olehovych  |" << endl;
    cout << "| Student of group KB-24                    |" << endl;
    cout << "| Educational institution: CNTU             |" << endl;
    cout << "==============================================" << endl;

    char input;
    while (true) {
        cout << "\nОберіть завдання:" << endl;
        cout << "v - (S=(x+y)*z)\n";
        cout << "n - (Розрахунок відсотків по депозиту)" << endl;
        cout << "m - (Конвертація розмірів чоловічої білизни)" << endl;
        cout << "q - (Підрахунок кількості біт у числі)" << endl;
        cout << "w - Вихід з програми" << endl;

        cout << "\nВведіть символ: ";
        cin >> input;

        switch (input) {
            case 'v': {
            cout << "\nОбчислення виразу S = (x + y) * z" << endl;
            double x, y, z;
            cout << "Введіть x:" << endl;
            cin >> x;
            cout << "Введіть y:" << endl;
            cin >> y;
            cout << "Введіть z:" << endl;
            cin >> z;
            calculation_s(x, y, z);
            break;
            }
            case 'n': {
                cout << "\nРозрахунок відсотків по депозиту" << endl;
                double amount;
                int months;
                cout << "Сума депозиту (грн): ";
                cin >> amount;
                cout << "Кількість місяців: ";
                cin >> months;
                double mani = CalculateInterest(amount,months);
                break;
            }
            case 'm': {
                cout << "\nКонвертація розмірів чоловічої білизни" << endl;
                int size;
                cout << "Введіть розмір (Словаччина): ";
                cin >> size;
                ConvertSize(size);
                break;
            }
            case 'q': {
                cout << "\nПідрахунок кількості біт" << endl;
                int N;
                cout << "Введіть число: ";
                cin >> N;
                CountBits(N);
                break;
            }
            case 'w':
            case 'W':
                cout << "\nЗавершення програми...\n";
                return 0;
            default:
                cout << "Невірне введення! Спробуйте ще раз.\a\n";
                break;
        }
    }
}
