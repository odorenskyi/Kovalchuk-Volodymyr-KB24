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
    cout << "��������� �������:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << ", S = " << S << endl;

    cout << "س������������ �������:" << hex << showbase;
    cout << "x = " << (int)x << ", y = " << (int)y <<", z = " << (int)z << ", S = " << (int)S << dec << endl;
}

    double CalculateInterest(double amount, int months) {
        double rate = months <= 6 ? 0.11 : 0.13;
        double monthlyInterest = (amount * rate) / 12;
        double totalInterest = monthlyInterest * months;

        std::cout << "̳����� �������: " << monthlyInterest << " ���\n";
        std::cout << "�������� ���� �������: " << totalInterest << " ���\n";
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
                std::cout << "�������� �����!" << std::endl;
                return;
        }
        std::cout << std::left << std::setw(20) << "�����" << "�����" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << std::left << std::setw(20) << "̳���������" << intl << std::endl;
        std::cout << std::left << std::setw(20) << "������" << ua << std::endl;
        std::cout << std::left << std::setw(20) << "������ �������" << uk << std::endl;
        std::cout << std::left << std::setw(20) << "ͳ�������" << de << std::endl;
        std::cout << std::left << std::setw(20) << "�������" << fr << std::endl;
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

        std::cout << "���������: " << count << std::endl; }
        double s_calculation(double x, double y, double z){
        return (x + y) * z;
    }

    void Task10_1(const string& input_filename, const string& output_filename) {
        ofstream outfile(output_filename);
        if (!outfile.is_open()) {
            cerr << "������� ��������: " << output_filename << endl;
            return;
        }

        // �������� ���
        outfile << "��������� ����������:\n";
        outfile << "��'�: ��������� ��������� ��������\n";
        outfile << "��������: ����, �. �������������, ������\n";
        outfile << "г�: 2025\n";

        // ��������� �����
        srand(time(0));
        int random = rand() % 91 + 10;
        outfile << "��������� ����� (10�100): " << random << "\n";

        // ���������� �����
        vector<string> original = {
            "�� ������� ���������� ����, �������� ����.",
            "������ � ���������� ����� �����.",
            "������� �� ������ ���� ��� ����.",
            "³��� � �������� ����� ���� ������ ������� ���,",
            "��� � ���� ���� ����� ������."
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
            cerr << "������� �������: " << input_filename << endl;
            read_error = true;
        }

        outfile << "�������� ����������:\n";
        if (read_error) {
            outfile << "�� ������� ��������� ������� ����.\n";
        } else if (input == original) {
            outfile << "����������� ������� ������.\n";
        } else {
            outfile << "�������� ����������� ������� ��� ��������� �� ��������.\n";
        }

        outfile << "--------------------------------------------\n";
        outfile.close();
    }

    void Task10_2(const string& filename) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            cerr << "������� ��������: " << filename << endl;
            return;
        }

        // ������
        file << "\n��������� ������: ";
        for (char c = 'A'; c <= 'Z'; ++c) file << c;
        file << "\n";

        // ���� � ���
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        file << "���� � ���: " << put_time(now, "%Y-%m-%d %H:%M:%S") << "\n";
        file << "--------------------------------------------\n";
        file.close();
    }
    void Task10_3(double x, double y, double z, unsigned int b, const string& filename) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            cerr << "������� ������ � ����: " << filename << endl;
            return;
        }
        double S = s_calculation(x, y, z);
        file << "���������: S = (x + y) * z\n";
        file << "x = " << x << ", y = " << y << ", z = " << z << ", S = " << S << "\n";

        file << "س������������ �������:\n";
        file << hex << showbase;
        file << "x = " << (int)x << ", y = " << (int)y << ", z = " << (int)z << ", S = " << (int)S << dec << "\n";

        file << "����� " << b << " � ��������� ���: " << bitset<16>(b) << "\n";
        file << "--------------------------------------------\n";
        file.close();
    }
