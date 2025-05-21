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
        cout << "\n������ ��:\n";
        cout << "1 - ����� ���������� �� ��������� ���������� (����)\n";
        cout << "2 - ������� ��������� ������ �� ���� � ������� ����\n";
        cout << "3 - ���������� ������ (x + y) * z �� ������� ������� �����\n";
        cout << "0 - ����� � ��������\n";
        cout << "��� ����: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n����: �������� ���� �� ����������� ������� �� ����� ���������� ����� � ����.\n";
                Task10_1(inputFile, outputFile);
                break;
        }
            case 2:{
                cout << "\n����: ������� ��������� ������ �� ������� ���� � ���� � ������� ����.\n";
                Task10_2(inputFile);
                break;
            }
            case 3: {
                cout << "\n����: ���������� ������ (x + y) * z � ������� ����� b � �������������� �� ������� ������.\n";
                double x, y, z;
                unsigned int b;
                cout << "������ x, y, z: ";
                cin >> x >> y >> z;
                cout << "������ ���������� ����� b: ";
                cin >> b;
                Task10_3(x, y, z, b, outputFile);
                break;
            }
            case 0:
                cout << "\n�������� ���������.\n";
                return 0;
            default:
                cout << "������� ����. ��������� �� ���.\n";
        }
    }

    return 0;
}
