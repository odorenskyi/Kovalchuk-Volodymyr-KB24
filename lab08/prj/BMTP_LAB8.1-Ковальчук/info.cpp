#include <iostream>
#include "mathlib.h"
using namespace std;

void show_about_me() {
    cout << "==============================================" << endl;
    cout << "| Task 8.1                                  |" << endl;
    cout << "| Calculation of the expression for x, y, z |" << endl;
    cout << "==============================================" << endl;
    cout << "|Developer:Kovalchuk Volodymyr Olehovych |" << endl;
    cout << "| Student of group KB-24                    |" << endl;
    cout << "| Educational institution: CNTU             |" << endl;
    cout << "==============================================" << endl;

        double x, y, z;
        cout << "Enter values for x, y, z: ";
        cin >> x >> y >> z;

        calculate_and_print(x, y, z);
}
