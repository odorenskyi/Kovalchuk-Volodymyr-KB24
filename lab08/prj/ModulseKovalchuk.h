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
    double a; // ������ ����� �����
    double b; // ���� ����� �����

    // �������� ������� ��� ����������� ����������� ������
    void printText(const char* text) const {
        cout << text;
    }

public:
    // ����������� �� �������������
    ClassLab12_Kovalchuk() : a(5.0), b(3.0) {
        printText("�������� ��������� ��� �� ������������� (a=");
        cout << a << ", b=" << b << ")" << endl;
    }

    // ����������� � �����������
    ClassLab12_Kovalchuk(double a_val, double b_val) : a(a_val), b(b_val) {
        printText("�������� ��������� ��� � ����������� (a=");
        cout << a << ", b=" << b << ")" << endl;
    }

    // ����������
    ~ClassLab12_Kovalchuk() {
        printText("������� ��'��� ���������� �����");
        cout << endl;
    }

    // ������ ��� ��������� ������� ��������
    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    // ������ ��� ������������ ������� ��������
    void setA(double new_a) {
        if (new_a > 0) {
            a = new_a;
            printText("����������� ���� �������� a = ");
            cout << a << endl;
        } else {
            printText("�������: �������� a ������� ���� ����� 0");
            cout << endl;
        }
    }

    void setB(double new_b) {
        if (new_b > 0) {
            b = new_b;
            printText("����������� ���� �������� b = ");
            cout << b << endl;
        } else {
            printText("�������: �������� b ������� ���� ����� 0");
            cout << endl;
        }
    }

    // ���������� ����� �����
    double calculateArea() const {
        return M_PI * a * b;
    }

    // ³���������� ���������� ��� ���
    void displayInfo() const {
        cout << fixed << setprecision(2);
        printText("=== ���������� ��� ��������� ��� ===");
        cout << endl;
        printText("������ ����� (a): ");
        cout << a << " ��." << endl;
        printText("���� ����� (b):   ");
        cout << b << " ��." << endl;
        printText("����� �������:     ");
        cout << calculateArea() << " ��.��." << endl;
        printText("=====================================");
        cout << endl;
    }

    // ��������� ����� �� ������
    bool isLargerThan(const ClassLab12_Kovalchuk& other) const {
        return this->calculateArea() > other.calculateArea();
    }

    // �������������� ��������� ������
    friend ostream& operator<<(ostream& os, const ClassLab12_Kovalchuk& table) {
        os << "��������� ��� [a=" << table.a << ", b=" << table.b
           << ", �����=" << table.calculateArea() << "]";
        return os;
    }
};

#endif // MODULSE_KOVALCHUK_H
