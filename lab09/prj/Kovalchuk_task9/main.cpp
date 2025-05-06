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
        cout << "\n������ ��������:" << endl;
        cout << "v - (S=(x+y)*z)\n";
        cout << "n - (���������� ������� �� ��������)" << endl;
        cout << "m - (����������� ������ ������� ������)" << endl;
        cout << "q - (ϳ�������� ������� �� � ����)" << endl;
        cout << "w - ����� � ��������" << endl;

        cout << "\n������ ������: ";
        cin >> input;

        switch (input) {
            case 'v': {
            cout << "\n���������� ������ S = (x + y) * z" << endl;
            double x, y, z;
            cout << "������ x:" << endl;
            cin >> x;
            cout << "������ y:" << endl;
            cin >> y;
            cout << "������ z:" << endl;
            cin >> z;
            calculation_s(x, y, z);
            break;
            }
            case 'n': {
                cout << "\n���������� ������� �� ��������" << endl;
                double amount;
                int months;
                cout << "���� �������� (���): ";
                cin >> amount;
                cout << "ʳ������ ������: ";
                cin >> months;
                double mani = CalculateInterest(amount,months);
                break;
            }
            case 'm': {
                cout << "\n����������� ������ ������� ������" << endl;
                int size;
                cout << "������ ����� (����������): ";
                cin >> size;
                ConvertSize(size);
                break;
            }
            case 'q': {
                cout << "\nϳ�������� ������� ��" << endl;
                int N;
                cout << "������ �����: ";
                cin >> N;
                CountBits(N);
                break;
            }
            case 'w':
            case 'W':
                cout << "\n���������� ��������...\n";
                return 0;
            default:
                cout << "������ ��������! ��������� �� ���.\a\n";
                break;
        }
    }
}
