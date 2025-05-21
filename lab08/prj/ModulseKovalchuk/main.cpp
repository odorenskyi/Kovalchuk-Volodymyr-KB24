#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
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

    double CalculateInterest(double amount, int months) {
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

        std::cout << "Результат: " << count << std::endl; }
        double s_calculation(double x, double y, double z){
        return (x + y) * z;
    }

    void Task10_1(const string& input_filename, const string& output_filename) {
        ofstream outfile(output_filename);
        if (!outfile.is_open()) {
            cerr << "Помилка відкриття: " << output_filename << endl;
            return;
        }

        // Авторські дані
        outfile << "Авторська інформація:\n";
        outfile << "Ім'я: Ковальчук Володимир Олегович\n";
        outfile << "Установа: ЦНТУ, м. Кропивницький, Україна\n";
        outfile << "Рік: 2025\n";

        // Випадкове число
        srand(time(0));
        int random = rand() % 91 + 10;
        outfile << "Випадкове число (10–100): " << random << "\n";

        // Очікуваний текст
        vector<string> original = {
            "Як парость виноградної лози, плекайте мову.",
            "Пильно й ненастанно політь бур’ян.",
            "Чистота від сльози вона хай буде.",
            "Вірно і слухняно нехай вона пораду служить вам,",
            "Хоч і живе своїм живим життям."
        };

        ifstream infile(input_filename);
        vector<string> input;
        string line;
        bool read_error = false;

        if (infile.is_open()) {
            while (getline(infile, line)) input.push_back(line);
            infile.close();
            if (!input.empty() && input.back().empty()) input.pop_back();
        } else {
            cerr << "Помилка читання: " << input_filename << endl;
            read_error = true;
        }

        outfile << "Перевірка пунктуації:\n";
        if (read_error) {
            outfile << "Не вдалося прочитати вхідний файл.\n";
        } else if (input == original) {
            outfile << "Пунктуаційні помилки відсутні.\n";
        } else {
            outfile << "Виявлено пунктуаційні помилки або відхилення від оригіналу.\n";
        }

        outfile << "--------------------------------------------\n";
        outfile.close();
    }

    void Task10_2(const string& filename) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            cerr << "Помилка відкриття: " << filename << endl;
            return;
        }

        // Алфавіт
        file << "\nАнглійська абетка: ";
        for (char c = 'A'; c <= 'Z'; ++c) file << c;
        file << "\n";

        // Дата і час
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        file << "Дата і час: " << put_time(now, "%Y-%m-%d %H:%M:%S") << "\n";
        file << "--------------------------------------------\n";
        file.close();
    }
    void Task10_3(double x, double y, double z, unsigned int b, const string& filename) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            cerr << "Помилка запису у файл: " << filename << endl;
            return;
        }
        double S = s_calculation(x, y, z);
        file << "Результат: S = (x + y) * z\n";
        file << "x = " << x << ", y = " << y << ", z = " << z << ", S = " << S << "\n";

        file << "Шістнадцяткова система:\n";
        file << hex << showbase;
        file << "x = " << (int)x << ", y = " << (int)y << ", z = " << (int)z << ", S = " << (int)S << dec << "\n";

        file << "Число " << b << " у двійковому коді: " << bitset<16>(b) << "\n";
        file << "--------------------------------------------\n";
        file.close();
    }
