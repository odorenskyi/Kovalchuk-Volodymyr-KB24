#include <cmath>
#include <iostream>
#include <iomanip>
#include <locale.h>
#include "s_calculation.h"

void s_calculation(double x, double y, double z) {
    double S = (x + y) * z;
    cout << "��������� �������:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << ", S = " << S << endl;

    cout << "س������������ �������:" << hex << showbase;
    cout << "x = " << (int)x << ", y = " << (int)y <<", z = " << (int)z << ", S = " << (int)S << dec << endl;
}
