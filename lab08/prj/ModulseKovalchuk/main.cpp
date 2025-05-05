#include <iostream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <string>
#include <cctype>
#include <ctime>
#include <sstream>
#include <bitset>
using namespace std;

void calculation_s(double x, double y, double z) {
    double S = (x + y) * z;
    cout << "Десяткова система:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << ", S = " << S << endl;

    cout << "Шістнадцяткова система:" << hex << showbase;
    cout << "x = " << (int)x << ", y = " << (int)y <<", z = " << (int)z << ", S = " << (int)S << dec << endl;
}


namespace MyLibrary {
    void CalculateInterest(double amount, int months) {
        double rate = months <= 6 ? 0.11 : 0.13;
        double monthlyInterest = (amount * rate) / 12;
        double totalInterest = monthlyInterest * months;

        std::cout << "Місячна виплата: " << monthlyInterest << " грн\n";
        std::cout << "Загальна сума відсотків: " << totalInterest << " грн\n";
    }

    void ConvertSize(int slovakSize) {
        std::string intl, ua, uk, de, fr;

        switch (slovakSize) {
            case 6: intl = "S"; ua = "44"; uk = "34"; de = "44"; fr = "46"; break;
            case 7: intl = "M"; ua = "46"; uk = "36"; de = "46"; fr = "48"; break;
            case 8: intl = "L"; ua = "48"; uk = "38"; de = "48"; fr = "50"; break;
            case 9: intl = "XL"; ua = "50"; uk = "40"; de = "50"; fr = "52"; break;
            case 10: intl = "XXL"; ua = "52"; uk = "42"; de = "52"; fr = "54"; break;
            default:
                std::cout << "Невідомий розмір!" << std::endl;
                return;
        }
        std::cout << std::left << std::setw(20) << "Країна" << "Розмір" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << std::left << std::setw(20) << "Міжнародний" << intl << std::endl;
        std::cout << std::left << std::setw(20) << "Україна" << ua << std::endl;
        std::cout << std::left << std::setw(20) << "Велика Британія" << uk << std::endl;
        std::cout << std::left << std::setw(20) << "Німеччина" << de << std::endl;
        std::cout << std::left << std::setw(20) << "Франція" << fr << std::endl;
    }

    void CountBits(int N) {
        std::string binary;
        int num = N;
        while (num > 0) {
            binary = std::to_string(num % 2) + binary;
            num /= 2;
        }

        int count = 0;
        char target = (N % 2 == 0) ? '0' : '1';
        for (char c : binary) {
            if (c == target) count++;
        }

        std::cout << "Результат: " << count << std::endl;
    }
}
